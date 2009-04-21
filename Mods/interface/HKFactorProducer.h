//--------------------------------------------------------------------------------------------------
// $Id: HKFactorProducer.h,v 1.1 2009/04/06 10:43:58 ceballos Exp $
//
// HKFactorProducer
//
// Produces the k factors from LO to NNLO.
//
// Authors: G. Gomez-Ceballos
//--------------------------------------------------------------------------------------------------

#ifndef MITPHYSICS_MODS_HKFACTORPRODUCER_H
#define MITPHYSICS_MODS_HKFACTORPRODUCER_H

#include "MitAna/TreeMod/interface/BaseMod.h" 
#include "MitAna/DataTree/interface/MCEventInfo.h"
#include "MitPhysics/Mods/interface/HWWKFactorList.h"

class TH1D;
class TH2D;

namespace mithep 
{
  class HKFactorProducer : public BaseMod
  {
    public:
      HKFactorProducer(const char *name="HKFactorProducer", 
                   const char *title="KFactor information module");
      ~HKFactorProducer();

      void               SetProcessID(Int_t d)	           { fProcessID     = d; }
      void               SetInputFilename(const char *s)   { fInputFileName = s; }
      void               SetMCBosonsName(const char *s)    { fMCBosonsName  = s; }
      void               SetMCEventInfoName(const char *s) { fMCEvInfoName  = s; }

    protected:
      void               Process();
      void               SlaveBegin();

      Int_t              fProcessID;        //process id (from pythia)
      TString            fInputFileName;    //input file name
      TString            fMCBosonsName;     //boson collection input name
      TString            fMCEvInfoName;     //event info branch name
      HWWKfactorList    *fPt_histo;         //!histogram with weights read from input file
      const MCEventInfo *fMCEventInfo;      //!event info branch pointer
      TH1D              *hDHKFactor[10];    //!output histograms

    ClassDef(HKFactorProducer, 1) // Module to produce k factors
  };
}
#endif