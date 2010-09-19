/*
Copyright (c) 1999 - 2010, Vodafone Group Services Ltd
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the name of the Vodafone Group Services Ltd nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef EXPAND_REQUEST_H
#define EXPAND_REQUEST_H

#include "config.h"
#include "SearchResultRequest.h"
#include <vector>

class ExpandRequestData;
class SearchReplyData;
class SearchRequestParameters;

/**
 *  Request that creates ExpandRequestPackets.
 */
class ExpandRequest : public SearchResultRequest {
  public:

   /**
    *  Constructor.
    *  @param parentOrID The RequestData.
    *  @param data The ExpandRequestData.
    */
   ExpandRequest(const RequestData& parentOrID,
                 const ExpandRequestData& data);

   /**
    *  Destructor.
    */
   ~ExpandRequest();

   /**
    *  Returns the status.
    *  @return The status.
    */
   StringTable::stringCode getStatus() const;

   /**
    *  Processes a packet.
    *  @param packet The packet to be processed.
    */
   void processPacket( PacketContainer* packet );

   /**
    *  Returns the vector with matches.
    *  @return The matches.
    */
   const vector<VanillaMatch*>& getMatches() const;

   /**
    *  Returns the search parameters, not used in this request.
    *  @return The search parameters.
    */
   const SearchRequestParameters& getSearchParameters() const;
   
   /// Overrides the one in SearchResultRequest
   uint32 getTotalNbrMatches() const;
   /// Overrides the one in SearchResultRequest
   int translateMatchIdx( int wantedIdx ) const;
   
   /// Calculates the CRC
   void calcCRC();

   /// Returns the CRC
   uint32 getCRC() const;
      
private:
   
   /// The reply data contains matches.
   SearchReplyData* m_replyData;  
   /// The status
   uint32 m_status;
   /// The search request parameters, not used in this request
   SearchRequestParameters* m_params;
   /// The CRC
   uint32 m_crc;
   
};

#endif // EXPAND_REQUEST_H
