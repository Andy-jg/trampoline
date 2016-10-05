#! /bin/sh

#
# @file tests.sh
#
# @section desc File description
#
# Trampoline Test Suite : Root script
#
# @section copyright Copyright
#
# Trampoline Test Suite
#
# Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
# Trampoline Test Suite is protected by the French intellectual property law.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; version 2
# of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#
# @section infos File informations
#
# $Date$
# $Rev$
# $Author$
# $URL$
#

# =============================================================================
# Script Environment variables
#
DEFAULTTARGET="posix"
AUTO_CLEAN=false
SCRIPT_DIR=$(cd $(dirname $0) && pwd -P)
PREVIOUS_TARGET=$SCRIPT_DIR/.tests_previous_target.sh
C_RED="\033[0;31m"
C_NOC="\033[0m"

# -----------------------------------------------------------------------------
# Server constants
#
# Remote server default address.
# If not set, the compilation will be done localy.
DEFAULTSERVER=""
# Path to the remote trampoline directory (Ex: /home/jeanMichel/trampoline)
REMOTE_TPL_DIR=""
# Rsync excluded directories (when copying trampoline)
RSYNC_EXCLUDE="--exclude .git
               --exclude documentation
               --exclude goil
               --exclude examples"

# -----------------------------------------------------------------------------
# Arch
#
MACHINES_DIR="$SCRIPT_DIR/machines"
## These variables are set later
# Target's arch dependant directory
ARCH_DIR=
# Script that contains arch dependant shell functions
SHELL_ARCH_SCRIPT=
# Script that contains arch dependant oil definitions
GOIL_ARCH_SCRIPT=
# C source file that contains arch dependant C functions for embUnit library
EMBUNIT_ARCH_SOURCE=

# -----------------------------------------------------------------------------
# Embunit
#
EMBUNIT_DIR="$SCRIPT_DIR/embUnit"
EMBUNIT_LIB="$SCRIPT_DIR/lib/libembUnit.a"

# -----------------------------------------------------------------------------
# Trampoline relative paths
#
TPL_DIR="$(realpath $SCRIPT_DIR/..)"
TPL_TEMPLATES_DIR="$TPL_DIR/goil/templates"
TPL_GOILV2_TEMPLATES_DIR="$TPL_DIR/goilv2/templates"

# -----------------------------------------------------------------------------
# Functional Tests
#
FUNCTIONAL_DIR="$SCRIPT_DIR/functional"
# Output results file
FUNCTIONAL_RESULTS="$SCRIPT_DIR/functional_results.log"
# Expected results. The file functional_results_expected.log in the target's
# arch directory is prioritized if it exists.
DEFAULT_FUNCTIONAL_RESULTS_EXPECTED="$FUNCTIONAL_DIR/functional_results_expected.log"
FUNCTIONAL_RESULTS_EXPECTED=
# Tests to make. The file functional_testSequence.txt in the target's
# arch directory is prioritized if it exists.
DEFAULT_FUNCTIONAL_TEST_SEQUENCE="$FUNCTIONAL_DIR/functional_testSequences.txt"
FUNCTIONAL_TEST_SEQUENCE=

# -----------------------------------------------------------------------------
# Goil Tests
#
GOIL_DIR="$SCRIPT_DIR/GOIL"
# Output results file
GOIL_RESULTS="$SCRIPT_DIR/GOIL_results.log"
# Expected results. The file GOIL_results_expected.log in the target's
# arch directory is prioritized if it exists.
DEFAULT_GOIL_RESULTS_EXPECTED="$GOIL_DIR/GOIL_results_expected.log"
GOIL_RESULTS_EXPECTED=
# Tests to make. The file GOIL_testSequence.txt in the target's
# arch directory is prioritized if it exists.
DEFAULT_GOIL_TEST_SEQUENCE="$GOIL_DIR/GOIL_testSequences.txt"
GOIL_TEST_SEQUENCE=

# =============================================================================
# Architecture dependant shell functions interface
#
# These functions are defined in the machines/$target/arch.sh file (stored in
# $SHELL_ARCH_SCRIPT variable and are only used to simplify the calls.

arch_execute()
{
  $SHELL_ARCH_SCRIPT arch_execute $@
}

arch_compile()
{
  if [ ! $server = "" ]; then
    arch_remote_compile $@
  else
    $SHELL_ARCH_SCRIPT arch_compile $@
  fi
}

arch_remote_compile()
{
  # Compute server's test and arch directory
  TEST_REL_PATH_FROM_TPL_DIR=$(echo "$TEST_DIR" | sed "s#$TPL_DIR/\?##")
  REMOTE_TEST_DIR="$REMOTE_TPL_DIR/$TEST_REL_PATH_FROM_TPL_DIR"
  ARCH_SCRIPT_PATH_FROM_TPL_DIR=$(echo "$SHELL_ARCH_SCRIPT" | sed "s#$TPL_DIR/\?##")
  REMOTE_ARCH_SCRIPT="$REMOTE_TPL_DIR/$ARCH_SCRIPT_PATH_FROM_TPL_DIR"

  # Synchronise files with the server
  rsync -az $TPL_DIR/ $RSYNC_EXCLUDE $server:$REMOTE_TPL_DIR

  # Remote Compile
  ssh $server "cd $REMOTE_TEST_DIR;
                  $REMOTE_ARCH_SCRIPT arch_compile $@;" &

  # Get executable
  scp $server:$REMOTE_TEST_DIR/${i}_exe .
}

# =============================================================================
# Internal functions
#

print_help()
{
    echo "Usage : $0 [ARGS] <TARGET>"
    echo "Possible Arguments :"
    echo "  -t  <TARGET> : Select target <Target> (default : posix). Can be"
    echo "                 ommited by giving the target as the last argument."
    echo "  -r  <Server> : Compile on the remote server <Server>."
    echo "  -f  : Functional tests."
    echo "  -g  : Goil tests."
    echo "  -a  : Functional and goil tests (equivalent to -gf)."
    echo "  -c  : Clean"
    echo "  -h  : print_help"
}

# ----------------------------------------------------------------------------
# functional_test_check_success
#
# Check the successfulness of the functional tests.
functional_test_check_success()
{
  echo "Comparing : $FUNCTIONAL_RESULTS"
  echo "With      : $FUNCTIONAL_RESULTS_EXPECTED"
  differences=$(diff -y $FUNCTIONAL_RESULTS_EXPECTED $FUNCTIONAL_RESULTS | wc -l)
  if [ $differences -eq 0 ]
  then
    echo "Functional tests Succeed!!"
  else
    echo "Functional tests FAILED with $differences differences..."
    echo "Results are stored in $FUNCTIONAL_RESULTS"
  fi
}

# ----------------------------------------------------------------------------
# goil_test_check_success
#
# Check the successfulness of the goil tests.
goil_test_check_success()
{
  echo "Comparing : $GOIL_RESULTS"
  echo "With      : $GOIL_RESULTS_EXPECTED"
  differences=$(diff -y $GOIL_RESULTS_EXPECTED $GOIL_RESULTS | wc -l)
  if [ $differences -eq 0 ]
  then
    echo "GOIL tests Succeed!!"
  else
    echo "GOIL tests FAILED with $differences differences..."
    echo "Results are stored in $GOIL_RESULTS"
  fi
}

# ----------------------------------------------------------------------------
# functional_test
#
functional_test()
{
  # Create an empty log file
  > $FUNCTIONAL_RESULTS

  # Make embUnit
  echo "===================================================================="
  echo "= Make embunit"
  if [ ! $(echo $target | grep "posix") = "" ]; then
    make -C $EMBUNIT_DIR
    retval=$?
  else
    make -C $EMBUNIT_DIR ARCH_CUSTOM_SOURCE=$EMBUNIT_ARCH_SOURCE
    retval=$?
  fi

  if [ ! $retval -eq 0 ]; then
    (>&2 echo "${C_RED}Fatal Error: Compilation of libemb failed.$C_NOC")
    exit 1
  fi

  total_tests=$(cat $FUNCTIONAL_TEST_SEQUENCE | grep "^\s*[^# ]")
  total_tests_count=$(echo "$total_tests" | wc -l)
  current_tests_count=0

  # Build and execute all the tests
  for i in $total_tests
  do
    TEST_DIR="$FUNCTIONAL_DIR/${i}"
    current_tests_count=$(($current_tests_count + 1))

    # Go in the test sequence
    cd $TEST_DIR

    # display running test sequence on the standard output for the user and
    # in the log file to better understand failed tests
    echo "> [$current_tests_count/$total_tests_count] : $i" | tee -a $FUNCTIONAL_RESULTS

    # remove the executable file in order to know if the make succeeded.
    rm -rf ./${i}_exe

    # check if previous target compiled is the same as the one wanted. If
    # not, clean all and compile
    if [ -f Make-rules ] && [ "$(cat Make-rules | grep GOIL_TARGET | grep -c $1)" = "0" ]
    then
      echo "(previous target different than $1 -> Recompilation...)"
      rm -rf ./build
      rm -rf ./${i}
      rm -rf ./Make-rules
      rm -rf ./Makefile
      rm -rf ./make.py
      rm -rf ./build.py
    fi

    retval=0
    # if Makefile doesn't exist -> do goil
    #if ! [ -e Makefile ]
    #then
      err=$(goil --target=$target ${i}.oil 2>&1)
      retval=$?
    #fi

    # if goil succeed -> do make
    if [ $retval -eq 0 ]
    then
      err=$(arch_compile $TEST_DIR 2>&1)
    else
      echo "$err" | tee -a $FUNCTIONAL_RESULTS
      echo "...\nfailure during Goil Generation.\n" | tee -a $FUNCTIONAL_RESULTS
      continue
    fi

    # if compilation succeed (Executable has been created) -> execute
    # TODO : Get execution's retval
    if [ -e ${i}_exe ]
    then
      arch_execute ./${i}_exe >> $FUNCTIONAL_RESULTS
    else
      echo "$err" | tee -a $FUNCTIONAL_RESULTS
      echo "...\nfailure during Compilation.\n" | tee -a $FUNCTIONAL_RESULTS
      continue
    fi

    # if execution failed (Return value != 0), print an error (can happen in
    # case of segmentation faults in posix for instance)
    if [ $? -ne 0 ]
    then
      echo "...\nfailure during Execution.\n" | tee -a $FUNCTIONAL_RESULTS
      continue
    fi

    cd $SCRIPT_DIR

  done
  echo "Functional tests done."
}

# ----------------------------------------------------------------------------
# goil_test
#
goil_test()
{
  # Create an empty log file
  > $GOIL_RESULTS

  total_tests=$(cat $GOIL_TEST_SEQUENCE | grep "^\s*[^# ]")
  total_tests_count=$(echo "$total_tests" | wc -l)
  current_tests_count=0

  # Build and execute all the tests
  for i in $total_tests
  do
    TEST_DIR="$GOIL_DIR/${i}"
    current_tests_count=$(($current_tests_count + 1))

    # Go in the test sequence
    cd $TEST_DIR

    # display running test sequence on the standard output for the user and
    # in the log file to better understand failed tests
    echo "> [$current_tests_count/$total_tests_count] : $i" | tee -a $GOIL_RESULTS

    err=$(goil --target=$target --templates=$TPL_GOILV2_DIR ${i}.oil 2>&1)
    retval=$?

    if [ ! $retval -eq 0 ]
    then
      echo "  Test failed"
      echo "$err" >> $GOIL_RESULTS
    fi
  done

  # replace pwd by CHECKPATH in GOIL_results.log
  output=$(cat $GOIL_RESULTS | sed -e "s/`pwd | sed 's_\/_\\\/_g'`/CHECKPATH/g")
  echo "$output" > $GOIL_RESULTS

  echo "Goil tests done."
}

# =============================================================================
# Parameters reading
#

# Reset shell script invocation counter
OPTIND=1

# Parameters default values
target=$DEFAULTTARGET
server=$DEFAULTSERVER
test_functional=0
test_goil=0
clean=0

# Parameters reading
while getopts "t:r:fgach" OPT; do
  case "$OPT" in
    t) target=$OPTARG;;
    r) server=$OPTARG;;
    f) test_functional=1;;
    g) test_goil=1;;
    a) test_functional=1;
       test_goil=1;;
    c) clean=1;;
    h) print_help;
       exit 0;;
    *) echo "Unknown parameter or wrong number of arguments";
       print_help;
       exit 1;;
  esac
done

# If there is a remaining argument, it must be the target
shift $((OPTIND - 1))
if [ $# -eq 1 ]; then
  target=$1
fi

# If the target is different from the last tested target, clean before testing
if [ -e $PREVIOUS_TARGET ] && [ $clean -eq 0 ]; then
  if [ ! $(cat $PREVIOUS_TARGET) = $target ]; then
    if $AUTO_CLEAN; then
      clean=1
    else
      echo "${C_RED}Fatal Error: Previous target different from the current."\
           "Cleaning required !$C_NOC"
      echo "You can set the AUTO_CLEAN variable to 'true' to avoid this case."
      exit 1
    fi
  fi
fi

# If remote compilation, test the environment
if [ ! "$server" = "" ]; then
  if [ "$REMOTE_TPL_DIR" = "" ]; then
    echo "${C_RED}Fatal Error: Requested a server compilation but server's"\
         " trampoline directory is not set !$C_NOC"
    exit 1
  fi
fi

# =============================================================================
# Main
#

# ----------------------------------------------------------------------------
# Clean target
#
if [ $clean -eq 1 ] ; then

  ## Common files
  # Delete embUnit's objects and librairy
  make -C $EMBUNIT_DIR clean -s
  rm -f $EMBUNIT_DIR/*.o  # Remove arch dependant object files

  ## GOIL tests directory
  # Delete results.log
  rm -f $GOIL_RESULTS

  ## FUNCTIONAL tests directory
  # Delete results.log
  rm -f $FUNCTIONAL_RESULTS

  # Files' builds
  for i in $(echo $FUNCTIONAL_DIR/*/); do
    rm -rf ${i}/build
    rm -rf ${i}/Makefile
    rm -rf ${i}/make.py
    rm -rf ${i}/build.py
    rm -rf ${i}/$(basename $i)_exe
    rm -rf ${i}/$(basename $i)
    rm -rf ${i}/goil.log
  done
  # Files' builds
  for i in $(echo $GOIL_DIR/*/); do
    rm -rf ${i}/build
    rm -rf ${i}/Makefile
    rm -rf ${i}/make.py
    rm -rf ${i}/build.py
    rm -rf ${i}/$(basename $i)_exe
    rm -rf ${i}/$(basename $i)
    rm -rf ${i}/goil.log
  done

  # Previous target
  rm -f $PREVIOUS_TARGET
fi

# ----------------------------------------------------------------------------
# Run Goil/Functional tests
#
if [ $test_goil -eq 1 ] || [ $test_functional -eq 1 ]; then
  ## Set architecture dependants variables
  ARCH_DIR=$MACHINES_DIR/$target
  # Needed
  SHELL_ARCH_SCRIPT=$ARCH_DIR/arch.sh
  GOIL_ARCH_SCRIPT=$ARCH_DIR/arch.oil
  EMBUNIT_ARCH_SOURCE=$ARCH_DIR/ArchEmb.c
  # If the following files don't exist, the default files will be considered
  FUNCTIONAL_TEST_SEQUENCE=$ARCH_DIR/functional_testSequences.txt
  FUNCTIONAL_RESULTS_EXPECTED=$ARCH_DIR/functional_results_expected.log
  GOIL_TEST_SEQUENCE=$ARCH_DIR/GOIL_testSequences.txt
  GOIL_RESULTS_EXPECTED=$ARCH_DIR/GOIL_results_expected.log

  ## Set GOIL's environment variables
  export GOIL_INCLUDE_PATH="$ARCH_DIR"
  export GOIL_TEMPLATES="$TPL_TEMPLATES_DIR"

  ## Tests the needed arch dependant files beforehand
  if [ ! -e $SHELL_ARCH_SCRIPT ]; then
    echo "${C_RED}Fatal Error: Missing target script $SHELL_ARCH_SCRIPT."
    echo "Bad target $target.${C_NOC}"
    echo "Possible targets are located in the $MACHINES_DIR directory."
    exit 1
  fi
  if [ ! -e $GOIL_ARCH_SCRIPT ]; then
    echo "${C_RED}Fatal Error: Missing target oil $GOIL_ARCH_SCRIPT."
    echo "Bad target $target.${C_NOC}"
    echo "Possible targets are located in the $MACHINES_DIR directory."
    exit 1
  fi
  if [ ! -e $GOIL_TEST_SEQUENCE ] || [ ! -e $GOIL_RESULTS_EXPECTED ]; then
    GOIL_TEST_SEQUENCE=$DEFAULT_GOIL_TEST_SEQUENCE
    GOIL_RESULTS_EXPECTED=$DEFAULT_GOIL_RESULTS_EXPECTED
  fi
  if [ ! -e $FUNCTIONAL_TEST_SEQUENCE ] || [ ! -e $FUNCTIONAL_RESULTS_EXPECTED ]; then
    FUNCTIONAL_TEST_SEQUENCE=$DEFAULT_FUNCTIONAL_TEST_SEQUENCE
    FUNCTIONAL_RESULTS_EXPECTED=$DEFAULT_FUNCTIONAL_RESULTS_EXPECTED
  fi

  # Set the previous target's variable
  echo $target > $PREVIOUS_TARGET

  ## Run requested tests
  if [ $test_goil -eq 1 ] ; then
    echo "===================================================================="
    echo "= Begin goil tests on target $target"
    echo "= Arch directory : $ARCH_DIR"
    echo "= Test sequence : $GOIL_TEST_SEQUENCE"
    goil_test
  fi
  if [ $test_functional -eq 1 ] ; then
    echo "===================================================================="
    echo "= Begin functional tests on target $target"
    echo "= Arch directory : $ARCH_DIR"
    echo "= Test sequence : $FUNCTIONAL_TEST_SEQUENCE"
    functional_test
  fi

  ## Check tests' successfulness
  if [ $test_goil -eq 1 ] ; then
    echo "===================================================================="
    echo "= Comparing results with the expected ones : GOIL tests"
    goil_test_check_success
  fi
  if [ $test_functional -eq 1 ] ; then
    echo "===================================================================="
    echo "= Comparing results with the expected ones : FUNCTIONAL tests"
    functional_test_check_success
  fi
fi

# ----------------------------------------------------------------------------
# Default : print help
#
if [ $clean -eq 0 ] && [ $test_functional -eq 0 ] && [ $test_goil -eq 0 ]; then
    print_help
fi

