CBOP
C !ROUTINE: ECCO_OPTIONS.h
C !INTERFACE:
C #include "ECCO_OPTIONS.h"

C !DESCRIPTION:
C *==================================================================*
C | CPP options file for ECCO (ecco) package:
C | Control which optional features to compile in this package code.
C *==================================================================*
CEOP

#ifndef ECCO_OPTIONS_H
#define ECCO_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_ECCO
#ifdef ECCO_CPPOPTIONS_H

C-- When multi-package option-file ECCO_CPPOPTIONS.h is used (directly included
C    in CPP_OPTIONS.h), this option file is left empty since all options that
C   are specific to this package are assumed to be set in ECCO_CPPOPTIONS.h

#else /* ndef ECCO_CPPOPTIONS_H */

C-- Package-specific Options & Macros go here

# undef ALLOW_ATEMP_COST_CONTRIBUTION
# undef ALLOW_AQH_COST_CONTRIBUTION
# undef ALLOW_UWIND_COST_CONTRIBUTION
# undef ALLOW_VWIND_COST_CONTRIBUTION
# undef ALLOW_PRECIP_COST_CONTRIBUTION
# undef ALLOW_SNOWPRECIP_COST_CONTRIBUTION
# undef ALLOW_SWDOWN_COST_CONTRIBUTION
# undef ALLOW_LWDOWN_COST_CONTRIBUTION
# undef ALLOW_EVAP_COST_CONTRIBUTION
# undef ALLOW_APRESSURE_COST_CONTRIBUTION
# undef ALLOW_RUNOFF_COST_CONTRIBUTION

# undef ALLOW_THETA0_COST_CONTRIBUTION
# undef ALLOW_SALT0_COST_CONTRIBUTION
# undef ALLOW_THETA_COST_CONTRIBUTION
# undef ALLOW_SALT_COST_CONTRIBUTION
# undef ALLOW_SST_COST_CONTRIBUTION
# undef ALLOW_SSS_COST_CONTRIBUTION

CML# define ALLOW_SSH_MEAN_COST_CONTRIBUTION
CML# define ALLOW_SSH_TPANOM_COST_CONTRIBUTION
CML# define ALLOW_SSH_ERSANOM_COST_CONTRIBUTION
CML# undef  ALLOW_SPH_PROJECTION
CML# if (defined (ALLOW_SSH_MEAN_COST_CONTRIBUTION) || \
CML      defined (ALLOW_SSH_TPANOM_COST_CONTRIBUTION) || \
CML      defined (ALLOW_SSH_ERSANOM_COST_CONTRIBUTION))
CML#  define ALLOW_SSH_COST_CONTRIBUTION
CML# endif

C allow for generic cost function and integral terms
#define ALLOW_GENCOST_CONTRIBUTION
#define ALLOW_GENCOST_SSTV4_OUTPUT
C allow for 3 dimensional generic terms
#define ALLOW_GENCOST3D

C include global mean steric sea level correction
#undef ALLOW_PSBAR_STERIC
C allow for near-shore and high-latitude altimetry
#undef ALLOW_SHALLOW_ALTIMETRY
#undef ALLOW_HIGHLAT_ALTIMETRY

C allow for In-Situ Profiles cost function contribution
#undef ALLOW_PROFILES_CONTRIBUTION

C cost function output format
#undef ALLOW_ECCO_OLD_FC_PRINT

C-- real options?

C include dump of snap shots for checks
#undef ALLOW_SNAPSHOTS

cph >>>>>> !!!!!! SPECIAL SEAICE FLAG FOR TESTING !!!!!! <<<<<<
c#define SEAICE_EXCLUDE_FOR_EXACT_AD_TESTING
cph >>>>>> !!!!!! SPECIAL SEAICE FLAG FOR TESTING !!!!!! <<<<<<

C generate more text in STDOUT.0000
#undef ECCO_VERBOSE

C allow cost function term for sigmaR
#undef ALLOW_SIGMAR_COST_CONTRIBUTION

C--  fake options (only used to be printed in S/R ECCO_SUMMARY):

C allow ???
#undef  ALLOW_ECCO_FORWARD_RUN
#undef  ALLOW_ECCO_DIAGNOSTIC_RUN
C Just do a "dry" run ( useful for testing ).
#undef  ALLOW_NO_DYNAMICS
C Use the Yearly-Monthly-Daily-Stepping call tree.
#undef  ALLOW_YMDS_TREE
C Do not call stepping
#undef ALLOW_STEPPING_CALL
C Projection onto Spherical Harmonics
#undef  ALLOW_SPH_PROJECTION

C   ==================================================================
#endif /* ndef ECCO_CPPOPTIONS_H */
#endif /* ALLOW_ECCO */
#endif /* ECCO_OPTIONS_H */
