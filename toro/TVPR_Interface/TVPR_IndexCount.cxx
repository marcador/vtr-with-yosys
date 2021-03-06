//===========================================================================//
// Purpose : Method definitions for the TVPR_IndexCount class.
//
//           Public methods include:
//           - TVPR_IndexCount_c, ~TVPR_IndexCount_c
//           - operator=, operator<
//           - operator==, operator!=
//           - Print
//           - ExtractString
//           - Clear
//
//===========================================================================//

//---------------------------------------------------------------------------//
// Copyright (C) 2012-2013 Jeff Rudolph, Texas Instruments (jrudolph@ti.com) //
//                                                                           //
// Permission is hereby granted, free of charge, to any person obtaining a   //
// copy of this software and associated documentation files (the "Software"),//
// to deal in the Software without restriction, including without limitation //
// the rights to use, copy, modify, merge, publish, distribute, sublicense,  //
// and/or sell copies of the Software, and to permit persons to whom the     //
// Software is furnished to do so, subject to the following conditions:      //
//                                                                           //
// The above copyright notice and this permission notice shall be included   //
// in all copies or substantial portions of the Software.                    //
//                                                                           //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   //
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                //
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN // 
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,  //
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR     //
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE //
// USE OR OTHER DEALINGS IN THE SOFTWARE.                                    //
//---------------------------------------------------------------------------//

#include "TIO_PrintHandler.h"

#include "TVPR_IndexCount.h"

//===========================================================================//
// Method         : TVPR_IndexCount_c
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
TVPR_IndexCount_c::TVPR_IndexCount_c( 
      void )
      :
      blockIndex_( INT_MAX ),
      nodeIndex_( INT_MAX ),
      siblingCount_( SIZE_MAX )
{
} 

//===========================================================================//
TVPR_IndexCount_c::TVPR_IndexCount_c( 
      int    blockIndex,
      int    nodeIndex,
      size_t siblingCount )
      :
      blockIndex_( blockIndex ),
      nodeIndex_( nodeIndex ),
      siblingCount_( siblingCount )
{
} 

//===========================================================================//
TVPR_IndexCount_c::TVPR_IndexCount_c( 
      const TVPR_IndexCount_c& indexCount )
      :
      blockIndex_( indexCount.blockIndex_ ),
      nodeIndex_( indexCount.nodeIndex_ ),
      siblingCount_( indexCount.siblingCount_ )
{
} 

//===========================================================================//
// Method         : ~TVPR_IndexCount_c
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
TVPR_IndexCount_c::~TVPR_IndexCount_c( 
      void )
{
}

//===========================================================================//
// Method         : operator=
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
TVPR_IndexCount_c& TVPR_IndexCount_c::operator=( 
      const TVPR_IndexCount_c& indexCount )
{
   if( &indexCount != this )
   {
      this->blockIndex_ = indexCount.blockIndex_;
      this->nodeIndex_ = indexCount.nodeIndex_;
      this->siblingCount_ = indexCount.siblingCount_;
   }
   return( *this );
}

//===========================================================================//
// Method         : operator<
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
bool TVPR_IndexCount_c::operator<( 
      const TVPR_IndexCount_c& indexCount ) const
{
   bool isLessThan = false;
   
   if( this->blockIndex_ < indexCount.blockIndex_ )
   {
      isLessThan = true;
   }
   if( this->blockIndex_ == indexCount.blockIndex_ )
   {
      if( this->nodeIndex_ < indexCount.nodeIndex_ )
      {
         isLessThan = true;
      }
   }
   return( isLessThan );
}

//===========================================================================//
// Method         : operator==
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
bool TVPR_IndexCount_c::operator==( 
      const TVPR_IndexCount_c& indexCount ) const
{
   return(( this->blockIndex_ == indexCount.blockIndex_ ) &&
          ( this->nodeIndex_ == indexCount.nodeIndex_ ) ?
          true : false );
}

//===========================================================================//
// Method         : operator!=
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
bool TVPR_IndexCount_c::operator!=( 
      const TVPR_IndexCount_c& indexCount ) const
{
   return( !this->operator==( indexCount ) ? true : false );
}

//===========================================================================//
// Method         : Print
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
void TVPR_IndexCount_c::Print( 
      FILE*  pfile,
      size_t spaceLen ) const
{
   string srIndexCount;
   this->ExtractString( &srIndexCount );

   TIO_PrintHandler_c& printHandler = TIO_PrintHandler_c::GetInstance( );
   printHandler.Write( pfile, spaceLen, "%s\n", TIO_SR_STR( srIndexCount ));
}

//===========================================================================//
// Method         : ExtractString
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
void TVPR_IndexCount_c::ExtractString( 
      string* psrIndexCount ) const
{
   if( psrIndexCount )
   {
      if( this->IsValid( ))
      {
         char szBlockIndex[TIO_FORMAT_STRING_LEN_VALUE];
         sprintf( szBlockIndex, "%d", this->blockIndex_ );

         char szNodeIndex[TIO_FORMAT_STRING_LEN_VALUE];
         sprintf( szNodeIndex, "%d", this->nodeIndex_ );

         *psrIndexCount = "";
         *psrIndexCount += szBlockIndex;
         *psrIndexCount += " ";
         *psrIndexCount += szNodeIndex;

         if( this->siblingCount_ != SIZE_MAX )
         {
            char szSiblingCount[TIO_FORMAT_STRING_LEN_VALUE];
            sprintf( szSiblingCount, "%lu", static_cast< unsigned long >( this->siblingCount_ ));

            *psrIndexCount += " ";
            *psrIndexCount += "[";
            *psrIndexCount += szSiblingCount;
            *psrIndexCount += "]";
         }
      }
      else
      {
         *psrIndexCount = "?";
      }
   }
} 

//===========================================================================//
// Method         : Clear
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 10/05/12 jeffr : Original
//===========================================================================//
void TVPR_IndexCount_c::Clear( 
      void )
{
   this->blockIndex_ = INT_MAX;
   this->nodeIndex_ = INT_MAX;
   this->siblingCount_ = SIZE_MAX;
} 
