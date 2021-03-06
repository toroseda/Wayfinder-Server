/*
Copyright (c) 1999 - 2010, Vodafone Group Services Ltd
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the name of the Vodafone Group Services Ltd nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "config.h"

#include "Packet.h"

#include "ItemInfoEntry.h"
#include "AlignUtility.h"

int
ItemInfoEntry::save( Packet* p, int& pos ) const
{
   int orig_pos = pos;
   p->incWriteString( pos, m_key );
   p->incWriteString( pos, m_val );
   p->incWriteLong  ( pos, m_infoType );
   return pos - orig_pos;
}

int
ItemInfoEntry::load( const Packet* p, int& pos ) 
{
   int orig_pos = pos;
   p->incReadString( pos, m_key );
   p->incReadString( pos, m_val );
   p->incReadLong( pos, m_infoType );
   return pos - orig_pos;
}

int
ItemInfoEntry::getSizeInPacket() const
{
   int len = m_key.length() + 1 + m_val.length() + 1 + 4;
   AlignUtility::alignLong( len );
   return len;
}
