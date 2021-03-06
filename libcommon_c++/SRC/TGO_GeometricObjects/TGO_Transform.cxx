//===========================================================================//
// Purpose : Method definitions for the TGO_Transform class.
//
//           Public methods include:
//           - TGO_Transform_c, ~TGO_Transform_c
//           - operator=
//           - operator==, operator!=
//           - Print
//           - ExtractString
//           - Apply
//           - Inverse
//
//===========================================================================//

//---------------------------------------------------------------------------//
// Copyright (C) 2013 Jeff Rudolph, Texas Instruments (jrudolph@ti.com)      //
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

#include "TGO_StringUtils.h"
#include "TGO_Transform.h"

//===========================================================================//
// Method         : TGO_Transform_c
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 01/15/13 jeffr : Original
//===========================================================================//
TGO_Transform_c::TGO_Transform_c( 
      void )
      :
      rotate_( TGO_ROTATE_UNDEFINED )
{
   this->origin_.Set( 0, 0, 0 );
   this->translate_.Set( 0, 0, 0 );
}

//===========================================================================//
TGO_Transform_c::TGO_Transform_c(
      const TGO_Point_c&     origin,
            TGO_RotateMode_t rotate, 
      const TGO_IntDims_t&   translate )
      :
      origin_( origin ),
      rotate_( rotate ),
      translate_( translate )
{
}

//===========================================================================//
TGO_Transform_c::TGO_Transform_c(
      const TGO_Point_c&     origin,
            TGO_RotateMode_t rotate, 
      const TGO_Point_c&     from,
      const TGO_Point_c&     to )
      :
      origin_( origin ),
      rotate_( rotate ),
      translate_( to.x - from.x, to.y - from.y, to.z - from.z )
{
}

//===========================================================================//
TGO_Transform_c::TGO_Transform_c(
            TGO_RotateMode_t rotate, 
      const TGO_IntDims_t&   translate )
      :
      rotate_( rotate ),
      translate_( translate )
{
   this->origin_.Set( 0, 0, 0 );
}

//===========================================================================//
TGO_Transform_c::TGO_Transform_c(
            TGO_RotateMode_t rotate, 
      const TGO_Point_c&     from,
      const TGO_Point_c&     to )
      :
      rotate_( rotate ),
      translate_( to.x - from.x, to.y - from.y, to.z - from.z )
{
   this->origin_.Set( 0, 0, 0 );
}

//===========================================================================//
// Method         : ~TGO_Transform_c
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 01/15/13 jeffr : Original
//===========================================================================//
TGO_Transform_c::~TGO_Transform_c( 
      void )
{
}

//===========================================================================//
// Method         : operator=, operator==, operator!=
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 01/15/13 jeffr : Original
//===========================================================================//
TGO_Transform_c& TGO_Transform_c::operator=( 
      const TGO_Transform_c& transform )
{
   if( &transform != this )
   {
      this->origin_ = transform.origin_;
      this->rotate_ = transform.rotate_;
      this->translate_ = transform.translate_;
   }
   return( *this );
}

//===========================================================================//
bool TGO_Transform_c::operator==( 
      const TGO_Transform_c& transform ) const
{
   return(( this->origin_ == transform.origin_ ) &&
          ( this->rotate_ == transform.rotate_ ) &&
          ( this->translate_ == transform.translate_ ) ?
          true : false );
}

//===========================================================================//
bool TGO_Transform_c::operator!=( 
      const TGO_Transform_c& transform ) const
{
   return(( !this->operator==( transform )) ? 
          true : false );
}

//===========================================================================//
// Method         : Print
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 01/15/13 jeffr : Original
//===========================================================================//
void TGO_Transform_c::Print(
      FILE*  pfile,
      size_t spaceLen ) const
{
   TIO_PrintHandler_c& printHandler = TIO_PrintHandler_c::GetInstance( );

   string srTransform;
   this->ExtractString( &srTransform );

   printHandler.Write( pfile, spaceLen, "[transform] %s\n", TIO_SR_STR( srTransform ));
}

//===========================================================================//
// Method         : ExtractString
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 01/15/13 jeffr : Original
//===========================================================================//
void TGO_Transform_c::ExtractString(
      string* psrTransform ) const
{
   if( psrTransform )
   {
      if( this->IsValid( ))
      {
         string srOrigin;
         this->origin_.ExtractString( &srOrigin );

         string srRotate;
         TGO_ExtractStringRotateMode( this->rotate_, &srRotate );

         string srTranslate;
         this->translate_.ExtractString( TC_DATA_INT, &srTranslate );

         *psrTransform = "";
         *psrTransform += "(";
         *psrTransform += srOrigin;
         *psrTransform += ")";
         *psrTransform += " ";
         *psrTransform += srRotate;
         *psrTransform += " ";
         *psrTransform += "[";
         *psrTransform += srTranslate;
         *psrTransform += "]";
      }
      else
      {
         *psrTransform = "(? ?) ? [? ? ?]";
      }
   }
}

//===========================================================================//
// Method         : Apply
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 01/15/13 jeffr : Original
//===========================================================================//
void TGO_Transform_c::Apply( 
      const TGO_Point_c& point, 
            TGO_Point_c* ppoint ) const
{
   if( ppoint )
   {
      *ppoint = point;

      // Step 1: Add translation to current point
      ppoint->x += this->translate_.dx;
      ppoint->y += this->translate_.dy;
      ppoint->z += this->translate_.dz;

      // Step 2: Subtract origin from given point
      ppoint->x -= this->origin_.x;
      ppoint->y -= this->origin_.y;

      // Step 3: Force rotation (and mirroring) on current point
      int x = ppoint->x;
      int y = ppoint->y;
      switch( this->rotate_ )
      {
      case TGO_ROTATE_R0:    ppoint->x =  1 * x; ppoint->y =  1 * y; break;
      case TGO_ROTATE_R90:   ppoint->x = -1 * y; ppoint->y =  1 * x; break;
      case TGO_ROTATE_R180:  ppoint->x = -1 * x; ppoint->y = -1 * y; break;
      case TGO_ROTATE_R270:  ppoint->x =  1 * y; ppoint->y = -1 * x; break;
      case TGO_ROTATE_MY:    ppoint->x = -1 * x; ppoint->y =  1 * y; break;
      case TGO_ROTATE_MYR90: ppoint->x = -1 * y; ppoint->y = -1 * x; break;
      case TGO_ROTATE_MX:    ppoint->x =  1 * x; ppoint->y = -1 * y; break;
      case TGO_ROTATE_MXR90: ppoint->x =  1 * y; ppoint->y =  1 * x; break;
      default:                                                       break;
      }

      // Step 4: Add origin to rotated point
      ppoint->x += this->origin_.x;
      ppoint->y += this->origin_.y;
   }
}

//===========================================================================//
void TGO_Transform_c::Apply( 
      const TGO_PointList_t& pointList, 
            TGO_PointList_t* ppointList ) const
{
   if( ppointList )
   {
      ppointList->Clear( );

      for( size_t i = 0; i < pointList.GetLength( ); ++i )
      {
         TGO_Point_c point = *pointList[i];

         this->Apply( point, &point );

         ppointList->Add( point );
      }
   }
}

//===========================================================================//
// Method         : Inverse
// Author         : Jeff Rudolph
//---------------------------------------------------------------------------//
// Version history
// 01/15/13 jeffr : Original
//===========================================================================//
void TGO_Transform_c::Inverse( 
      const TGO_Point_c& point, 
            TGO_Point_c* ppoint ) const
{
   if( ppoint )
   {
      *ppoint = point;

      // Step 1: Subtract origin from translated point
      ppoint->x -= this->origin_.x;
      ppoint->y -= this->origin_.y;

      // Step 2: Force rotation (and mirroring) on translated point
      int x = ppoint->x;
      int y = ppoint->y;
      switch( this->rotate_ )
      {
      case TGO_ROTATE_R0:    ppoint->x =  1 * x; ppoint->y =  1 * y; break;
      case TGO_ROTATE_R90:   ppoint->x =  1 * y; ppoint->y = -1 * x; break;
      case TGO_ROTATE_R180:  ppoint->x = -1 * x; ppoint->y = -1 * y; break;
      case TGO_ROTATE_R270:  ppoint->x = -1 * y; ppoint->y =  1 * x; break;
      case TGO_ROTATE_MY:    ppoint->x = -1 * x; ppoint->y =  1 * y; break;
      case TGO_ROTATE_MYR90: ppoint->x = -1 * y; ppoint->y = -1 * x; break;
      case TGO_ROTATE_MX:    ppoint->x =  1 * x; ppoint->y = -1 * y; break;
      case TGO_ROTATE_MXR90: ppoint->x =  1 * y; ppoint->y =  1 * x; break;
      default:                                                       break;
      }

      // Step 3: Add origin to rotated point
      ppoint->x += this->origin_.x;
      ppoint->y += this->origin_.y;

      // Step 4: Substract translation from given point
      ppoint->x -= this->translate_.dx;
      ppoint->y -= this->translate_.dy;
      ppoint->z -= this->translate_.dz;
   }
}

//===========================================================================//
void TGO_Transform_c::Inverse( 
      const TGO_PointList_t& pointList, 
            TGO_PointList_t* ppointList ) const
{
   if( ppointList )
   {
      ppointList->Clear( );

      for( size_t i = 0; i < pointList.GetLength( ); ++i )
      {
         TGO_Point_c point = *pointList[i];

         this->Inverse( point, &point );

         ppointList->Add( point );
      }
   }
}
