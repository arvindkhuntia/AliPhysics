/**************************************************************************
* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
*                                                                        *
* Author: The ALICE Off-line Project.                                    *
* Contributors are mentioned in the code where appropriate.              *
*                                                                        *
* Permission to use, copy, modify and distribute this software and its   *
* documentation strictly for non-commercial purposes is hereby granted   *
* without fee, provided that the above copyright notice appears in all   *
* copies and that both the copyright notice and this permission notice   *
* appear in the supporting documentation. The authors make no claims     *
* about the suitability of this software for any purpose. It is          *
* provided "as is" without express or implied warranty.                  *
**************************************************************************/
//
// Debug tree to look at the distribution of the variable we are cutting on
//
//
#ifndef ALIHFEREDUCEDEVENTCREATORESD_H
#define ALIHFEREDUCEDEVENTCREATORESD_H

#include "AliAnalysisTaskSE.h"

class TString;
class TTree;
class AliAnalysisUtils;
class AliPIDResponse;
class AliHFEcuts;
class AliHFEextraCuts;
class AliHFEpidTPC;
class AliTRDTriggerAnalysis; 
class AliHFEsignalCuts;
class AliHFEreducedEvent;

class AliHFEreducedEventCreatorESD : public AliAnalysisTaskSE{
  public:
    AliHFEreducedEventCreatorESD();
    AliHFEreducedEventCreatorESD(const char *name);
    virtual ~AliHFEreducedEventCreatorESD();

    virtual void UserCreateOutputObjects();
    virtual void UserExec(Option_t *);
    virtual void Terminate(Option_t *);

    // Setters for cuts
    void SetMinNclustersTPC(Int_t mincl) { fNclustersTPC = mincl; };
    void SetMinNclustersTPCPID(Int_t mincl) { fNclustersTPCPID = mincl; };
    void SetMinNclustersITS(Int_t mincl) { fNclustersITS = mincl; };
    void SetRemoveFirstEventFromChunk() { fRemoveFirstEvent = kTRUE; }
    AliHFEpidTPC *GetTPCResponse() { return fTPCpid; }

    Bool_t IsTOFmismatch(const AliVTrack *const track, const AliPIDResponse *const pid) const;
    
  private:
    AliHFEreducedEventCreatorESD(const AliHFEreducedEventCreatorESD &);
    AliHFEreducedEventCreatorESD &operator=(const AliHFEreducedEventCreatorESD &);
    
    TTree *fHFEtree;                  // HFE tree 
    AliAnalysisUtils *fAnalysisUtils; // Analysis Utils
    AliHFEreducedEvent *fHFEevent;    // hfe event
    AliHFEcuts *fTrackCuts;           // Track
    AliHFEextraCuts *fExtraCuts;      // HFE IP info
    AliHFEsignalCuts *fSignalCuts;    // Signal Cuts
    AliHFEpidTPC *fTPCpid;            // TPC PID
    AliTRDTriggerAnalysis *fTRDTriggerAnalysis; //! TRD Trigger Analysis 
    Int_t fEventNumber;               // Event Number
    Int_t fNclustersTPC;              // Min Number of clusters in TPC
    Int_t fNclustersTPCPID;           // Min Number of clusters for TPC PID
    Int_t fNclustersITS;              // Min Number of clusters in ITS
    Bool_t fRemoveFirstEvent;         // Remove first event from chunk
    
    ClassDef(AliHFEreducedEventCreatorESD, 1)
      };
#endif


