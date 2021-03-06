/*
Copyright (c) 1999 - 2010, Vodafone Group Services Ltd
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the name of the Vodafone Group Services Ltd nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SOCKETINTERFACEREQUEST_H
#define SOCKETINTERFACEREQUEST_H

#include "config.h"
#include "SelectableInterfaceRequest.h"

// Forward declarations
class Selectable;
class SocketBuffer;
class TCPSocket;

/**
 * Abstract super class for requests comming from outside mc2 that 
 * uses sockets to read and write data. Has some methods to help
 * develop new InterfaceRequests using a socket.
 * Subclasses must handle the creation and deletion of m_reqSock and
 * m_sockBuff.
 *
 */
class SocketInterfaceRequest : public SelectableInterfaceRequest {
   public:
      /**
       * Creates a new InterfaceRequest.
       */
      SocketInterfaceRequest();

      /**
       * Destructor.
       */
      virtual ~SocketInterfaceRequest();

      /**
       * The selectable.
       */
      virtual Selectable* getSelectable();

      /**
       * If read is wanted.
       */
      virtual bool wantRead() const;

      /**
       * If write is wanted.
       */
      virtual bool wantWrite() const;

      /**
       * Get the current log-prefix string.
       */
      const char* getLogPrefix() const;

      /**
       * Prints the current information about the request.
       */
      virtual ostream& dumpState( ostream& out ) const = 0;

      /**
       * Get the socket.
       */
      TCPSocket* getReqSock();

   protected: 
      /**
       * The socket to get and put data from and to.
       */
      TCPSocket* m_reqSock;

      /**
       * The read buffer for the m_reqSock.
       */
      SocketBuffer* m_sockBuff;

      /**
       * Read wants write or Write wants read.
       */
      bool m_invIO;

      /**
       * Logging prefix used to identify this session in the log.
       */
      char m_logPrefix[256];
};


// =======================================================================
//                                     Implementation of inlined methods =


inline const char*
SocketInterfaceRequest::getLogPrefix() const {
   return m_logPrefix;
}

inline TCPSocket*
SocketInterfaceRequest::getReqSock() {
   return m_reqSock;
}


#endif // SELECTABLEINTERFACEREQUEST_H

