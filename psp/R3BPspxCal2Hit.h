/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/
// ----------------------------------------------------------------
// -----                    R3BPspxCal2Hit                    -----
// -----	        created 09-03-2016 by I. Syndikus         -----
// -----              Modified  Dec 2019  by M. Holl		  -----
// ----------------------------------------------------------------

#ifndef R3BPSPXCAL2HIT_H
#define R3BPSPXCAL2HIT_H

#include "FairTask.h"

class TClonesArray;
class R3BEventHeader;
class R3BPspxHitPar;

/**
 * Class to convert Cal data to Hit data for PSPX detector data.
 * Total deposited energy is converted to MeV
 * Positions are converted to global coordinates in centimetres
 * @author Ina Syndikus
 * @since March 9, 2016
 * Modified Dec 2019 by M.Holl
 */

class R3BPspxCal2Hit : public FairTask
{
  public:
    /** Default Constructor **/
    R3BPspxCal2Hit();
    /**
     * Standard Constructor
     **/
    R3BPspxCal2Hit(const char* name, Int_t iVerbose);
    /** Destructor **/
    virtual ~R3BPspxCal2Hit();

    virtual InitStatus Init();
    InitStatus ReInit();
    void SetParContainers();
    void SetParameters();

    virtual void Exec(Option_t* option);

    virtual void FinishEvent();
    virtual void FinishTask();

  private:
    R3BEventHeader* fHeader;              // do we need that?
    std::vector<TClonesArray*> fCalItems; /**< Array holding input (Cal) data */
    std::vector<TClonesArray*> fHitItems; /**< Array holding output (Hit) data */

    R3BPspxHitPar* fHitPar; /**< Parameter instance holding slopes, offsets and signs */
    std::vector<Float_t> orientation;
    std::vector<Float_t> detSize;
    std::vector<Float_t> posOffset;
    std::vector<Float_t> posSlope;
    std::vector<Float_t> eOffset;
    std::vector<Float_t> eGain;
    std::vector<Float_t> eRange;

  public:
    ClassDef(R3BPspxCal2Hit, 4)
};

#endif
