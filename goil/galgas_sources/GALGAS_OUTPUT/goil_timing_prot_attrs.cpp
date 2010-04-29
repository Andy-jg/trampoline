//---------------------------------------------------------------------------*
//                                                                           *
//                    File 'goil_timing_prot_attrs.cpp'                      *
//                       Generated by version 1.9.11                         *
//                      april 29th, 2010, at 10h36'54"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 725
  #error "This file has been compiled with a version of GALGAS that uses libpm version 725, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_timing_prot_attrs.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_timing_prot_attrs.gSyntax", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'timing_prot_attrs'            *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_timing_prot_attrs::rule_goil_5F_timing_5F_prot_5F_attrs_timing_5F_prot_5F_attrs_i0_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_basic_type  &var_cas_exe_budget,
                                GGS_basic_type  &var_cas_exe_time,
                                GGS_basic_type  &var_cas_time_frame,
                                GGS_basic_type  &var_cas_os_it_lock,
                                GGS_basic_type  &var_cas_all_it_lock,
                                GGS_rezlock_map  &var_cas_rezlocks) {
  var_cas_exe_budget = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (29)) ;
  var_cas_exe_time = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (30)) ;
  var_cas_time_frame = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (31)) ;
  var_cas_os_it_lock = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (32)) ;
  var_cas_all_it_lock = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (33)) ;
  var_cas_rezlocks = GGS_rezlock_map ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (34)) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_timing_5F_prot_5F_attrs_0 (inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_eb ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_EXECUTIONBUDGET) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_eb) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_1437 = var_cas_exe_budget ; // CAST instruction
            if (_var_1437.getPtr () != NULL) {
              macroValidPointer (_var_1437.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_1437.getPtr ()))) {
                var_cas_exe_budget = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_eb.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (40)) COMMA_SOURCE_FILE_AT_LINE (40)) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EXECUTIONBUDGET already declared") COMMA_SOURCE_FILE_AT_LINE (43)) ;
                var_cas_exe_budget.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (43)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (44)) ;
              }
            }
          }
          } break ;
        case 3 : {
          GGS_luint64  var_cas_et ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_EXECUTIONTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_et) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_1794 = var_cas_exe_time ; // CAST instruction
            if (_var_1794.getPtr () != NULL) {
              macroValidPointer (_var_1794.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_1794.getPtr ()))) {
                var_cas_exe_time = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_et.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (49)) COMMA_SOURCE_FILE_AT_LINE (49)) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EXECUTIONTIME already declared") COMMA_SOURCE_FILE_AT_LINE (52)) ;
                var_cas_exe_time.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (52)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (53)) ;
              }
            }
          }
          } break ;
        case 4 : {
          GGS_luint64  var_cas_tf ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TIMEFRAME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_tf) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_2149 = var_cas_time_frame ; // CAST instruction
            if (_var_2149.getPtr () != NULL) {
              macroValidPointer (_var_2149.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_2149.getPtr ()))) {
                var_cas_time_frame = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_tf.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (58)) COMMA_SOURCE_FILE_AT_LINE (58)) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("TIMEFRAME already declared") COMMA_SOURCE_FILE_AT_LINE (61)) ;
                var_cas_time_frame.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (61)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (62)) ;
              }
            }
          }
          } break ;
        case 5 : {
          GGS_luint64  var_cas_moilt ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_MAXOSINTERRUPTLOCKTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_moilt) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_2539 = var_cas_os_it_lock ; // CAST instruction
            if (_var_2539.getPtr () != NULL) {
              macroValidPointer (_var_2539.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_2539.getPtr ()))) {
                var_cas_os_it_lock = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_moilt.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (67)) COMMA_SOURCE_FILE_AT_LINE (67)) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXOSINTERRUPTLOCKTIME already declared") COMMA_SOURCE_FILE_AT_LINE (70)) ;
                var_cas_os_it_lock.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (70)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (71)) ;
              }
            }
          }
          } break ;
        case 6 : {
          GGS_luint64  var_cas_maitl ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_MAXALLINTERRUPTLOCKTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_maitl) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          { const GGS_basic_type _var_2934 = var_cas_all_it_lock ; // CAST instruction
            if (_var_2934.getPtr () != NULL) {
              macroValidPointer (_var_2934.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_2934.getPtr ()))) {
                var_cas_all_it_lock = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_maitl.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (76)) COMMA_SOURCE_FILE_AT_LINE (76)) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXALLINTERRUPTLOCKTIME already declared") COMMA_SOURCE_FILE_AT_LINE (79)) ;
                var_cas_all_it_lock.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (79)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (80)) ;
              }
            }
          }
          } break ;
        case 7 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_LOCKINGTIME) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_RESOURCELOCK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
          GGS_lstring  var_cas_rez = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (83)) ;
          GGS_basic_type  var_cas_lock = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (84)) ;
          { bool syntaxRepeat_1 = true ;
            while (syntaxRepeat_1) {
              switch (select_goil_5F_timing_5F_prot_5F_attrs_1 (inLexique)) {
                case 2 : {
                  GGS_lstring  var_cas_r ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_RESOURCE) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
                  inLexique.assignFromAttribute_att_5F_token (var_cas_r) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
                  const GGS_bool cond_3381 = (var_cas_rez.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (89))).operator_isNotEqual (GGS_string ("")) ;
                  if (cond_3381.isBuiltAndTrue ()) {
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("RESOURCE already declared") COMMA_SOURCE_FILE_AT_LINE (91)) ;
                    var_cas_rez.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (92)) ;
                  }else if (cond_3381.isBuiltAndFalse ()) {
                    var_cas_rez = var_cas_r ;
                  }
                  } break ;
                case 3 : {
                  GGS_luint64  var_cas_mrlt ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_MAXRESOURCELOCKTIME) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
                  inLexique.assignFromAttribute_integerNumber (var_cas_mrlt) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
                  { const GGS_basic_type _var_3821 = var_cas_lock ; // CAST instruction
                    if (_var_3821.getPtr () != NULL) {
                      macroValidPointer (_var_3821.getPtr ()) ;
                      if (typeid (cPtr_void) == typeid (* (_var_3821.getPtr ()))) {
                        var_cas_lock = GGS_uint64_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_mrlt.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (99)) COMMA_SOURCE_FILE_AT_LINE (99)) ;
                      }else{
                        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXRESOURCELOCKTIME already declared") COMMA_SOURCE_FILE_AT_LINE (102)) ;
                        var_cas_lock.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (102)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously declared here") COMMA_SOURCE_FILE_AT_LINE (103)) ;
                      }
                    }
                  }
                  } break ;
                default :
                  syntaxRepeat_1 = false ;
                  break ;
              }
            }
          }
          const GGS_bool cond_3962 = (var_cas_rez.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (105))).operator_isEqual (GGS_string ("")) ;
          if (cond_3962.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("No RESOURCE declared for LOCKINGTIME") COMMA_SOURCE_FILE_AT_LINE (107)) ;
          }
          GGS_uint64  var_cas_l = GGS_uint64 (0ULL) ;
          { const GGS_basic_type _var_4170 = var_cas_lock ; // CAST instruction
            if (_var_4170.getPtr () != NULL) {
              macroValidPointer (_var_4170.getPtr ()) ;
              if (typeid (cPtr_uint64_class) == typeid (* (_var_4170.getPtr ()))) {
                const GGS_uint64_class var_cas_lu (_var_4170.getPtr ()) ;
                var_cas_l = var_cas_lu.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (111)) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("No MAXRESOURCELOCKTIME declared for LOCKINGTIME") COMMA_SOURCE_FILE_AT_LINE (114)) ;
              }
            }
          }
          var_cas_rezlocks.modifier_put (inLexique, var_cas_rez, var_cas_l COMMA_SOURCE_FILE_AT_LINE (115)) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  { const GGS_basic_type _var_4339 = var_cas_time_frame ; // CAST instruction
    if (_var_4339.getPtr () != NULL) {
      macroValidPointer (_var_4339.getPtr ()) ;
      if (typeid (cPtr_void) == typeid (* (_var_4339.getPtr ()))) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("TIMEFRAME not declared") COMMA_SOURCE_FILE_AT_LINE (119)) ;
      }else{
      }
    }
  }
  { const GGS_basic_type _var_4448 = var_cas_os_it_lock ; // CAST instruction
    if (_var_4448.getPtr () != NULL) {
      macroValidPointer (_var_4448.getPtr ()) ;
      if (typeid (cPtr_void) == typeid (* (_var_4448.getPtr ()))) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXOSINTERRUPTLOCKTIME not declared") COMMA_SOURCE_FILE_AT_LINE (120)) ;
      }else{
      }
    }
  }
  { const GGS_basic_type _var_4558 = var_cas_all_it_lock ; // CAST instruction
    if (_var_4558.getPtr () != NULL) {
      macroValidPointer (_var_4558.getPtr ()) ;
      if (typeid (cPtr_void) == typeid (* (_var_4558.getPtr ()))) {
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MAXALLINTERRUPTLOCKTIME not declared") COMMA_SOURCE_FILE_AT_LINE (121)) ;
      }else{
      }
    }
  }
}

//---------------------------------------------------------------------------*

