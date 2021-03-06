//===========================================================================//
// Purpose : Enums, typedefs, and defines for TOS_OptionsStore classes.
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

#ifndef TOS_TYPEDEFS_H
#define TOS_TYPEDEFS_H

#include "TC_Name.h"
#include "TC_NameFile.h"
#include "TCT_NameList.h"

//---------------------------------------------------------------------------//
// Define pack option constants and typedefs
//---------------------------------------------------------------------------//

enum TOS_PackAlgorithmMode_e
{
   TOS_PACK_ALGORITHM_UNDEFINED = 0,
   TOS_PACK_ALGORITHM_AAPACK
};
typedef enum TOS_PackAlgorithmMode_e TOS_PackAlgorithmMode_t;

enum TOS_PackClusterNetsMode_e
{
   TOS_PACK_CLUSTER_NETS_UNDEFINED = 0,
   TOS_PACK_CLUSTER_NETS_MIN_CONNECTIONS,
   TOS_PACK_CLUSTER_NETS_MAX_CONNECTIONS
};
typedef enum TOS_PackClusterNetsMode_e TOS_PackClusterNetsMode_t;

enum TOS_PackAffinityMode_e
{
   TOS_PACK_AFFINITY_UNDEFINED = 0,
   TOS_PACK_AFFINITY_NONE,
   TOS_PACK_AFFINITY_ANY
};
typedef enum TOS_PackAffinityMode_e TOS_PackAffinityMode_t;

enum TOS_PackCostMode_e
{
   TOS_PACK_COST_UNDEFINED = 0,
   TOS_PACK_COST_ROUTABILITY_DRIVEN,
   TOS_PACK_COST_TIMING_DRIVEN
};
typedef enum TOS_PackCostMode_e TOS_PackCostMode_t;

//---------------------------------------------------------------------------//
// Define place option constants and typedefs
//---------------------------------------------------------------------------//

enum TOS_PlaceAlgorithmMode_e
{
   TOS_PLACE_ALGORITHM_UNDEFINED = 0,
   TOS_PLACE_ALGORITHM_ANNEALING
};
typedef enum TOS_PlaceAlgorithmMode_e TOS_PlaceAlgorithmMode_t;

enum TOS_PlaceCostMode_e
{
   TOS_PLACE_COST_UNDEFINED = 0,
   TOS_PLACE_COST_ROUTABILITY_DRIVEN,
   TOS_PLACE_COST_PATH_TIMING_DRIVEN,
   TOS_PLACE_COST_NET_TIMING_DRIVEN
};
typedef enum TOS_PlaceCostMode_e TOS_PlaceCostMode_t;

enum TOS_PlaceRelativeDefs_e
{
   TOS_PLACE_RELATIVE_INITIAL_PLACE_RETRY = 3,
   TOS_PLACE_RELATIVE_INITIAL_MACRO_RETRY = 10
};

//---------------------------------------------------------------------------//
// Define route option constants and typedefs
//---------------------------------------------------------------------------//

enum TOS_RouteAlgorithmMode_e
{
   TOS_ROUTE_ALGORITHM_UNDEFINED = 0,
   TOS_ROUTE_ALGORITHM_PATHFINDER
};
typedef enum TOS_RouteAlgorithmMode_e TOS_RouteAlgorithmMode_t;

enum TOS_RouteAbstractMode_e
{
   TOS_ROUTE_ABSTRACT_UNDEFINED = 0,
   TOS_ROUTE_ABSTRACT_GLOBAL,
   TOS_ROUTE_ABSTRACT_DETAILED
};
typedef enum TOS_RouteAbstractMode_e TOS_RouteAbstractMode_t;

enum TOS_RouteResourceMode_e
{
   TOS_ROUTE_RESOURCE_UNDEFINED = 0,
   TOS_ROUTE_RESOURCE_DEMAND_ONLY,
   TOS_ROUTE_RESOURCE_DELAY_NORMALIZED
};
typedef enum TOS_RouteResourceMode_e TOS_RouteResourceMode_t;

enum TOS_RouteCostMode_e
{
   TOS_ROUTE_COST_UNDEFINED = 0,
   TOS_ROUTE_COST_BREADTH_FIRST,
   TOS_ROUTE_COST_TIMING_DRIVEN
};
typedef enum TOS_RouteCostMode_e TOS_RouteCostMode_t;

enum TOS_RouteOrderMode_e 
{ 
   TOS_ROUTE_ORDER_UNDEFINED,
   TOS_ROUTE_ORDER_FIRST,
   TOS_ROUTE_ORDER_AUTO
};
typedef enum TOS_RouteOrderMode_e TOS_RouteOrderMode_t;

//---------------------------------------------------------------------------//
// Define input option constants and typedefs
//---------------------------------------------------------------------------//

typedef TCT_NameList_c< TC_Name_c > TOS_OptionsNameList_t;

//---------------------------------------------------------------------------//
// Define output option constants and typedefs
//---------------------------------------------------------------------------//

enum TOS_OutputLaffMask_e
{
   TOS_OUTPUT_LAFF_UNDEFINED     = 0x00,
   TOS_OUTPUT_LAFF_NONE          = 0x00,
   TOS_OUTPUT_LAFF_FABRIC_VIEW   = 0x01,
   TOS_OUTPUT_LAFF_BOUNDING_BOX  = 0x02,
   TOS_OUTPUT_LAFF_INTERNAL_GRID = 0x04,
   TOS_OUTPUT_LAFF_ALL           = TOS_OUTPUT_LAFF_FABRIC_VIEW |
                                   TOS_OUTPUT_LAFF_BOUNDING_BOX
};
typedef enum TOS_OutputLaffMask_e TOS_OutputLaffMask_t;

enum TOS_RcDelaysExtractMode_e
{
   TOS_RC_DELAYS_EXTRACT_UNDEFINED = 0,
   TOS_RC_DELAYS_EXTRACT_ELMORE,
   TOS_RC_DELAYS_EXTRACT_D2M
};
typedef enum TOS_RcDelaysExtractMode_e TOS_RcDelaysExtractMode_t;

enum TOS_RcDelaysSortMode_e
{
   TOS_RC_DELAYS_SORT_UNDEFINED = 0,
   TOS_RC_DELAYS_SORT_BY_NETS,
   TOS_RC_DELAYS_SORT_BY_DELAYS
};
typedef enum TOS_RcDelaysSortMode_e TOS_RcDelaysSortMode_t;

typedef TCT_NameList_c< TC_Name_c > TOS_RcDelaysNameList_t;

//---------------------------------------------------------------------------//
// Define message option constants and typedefs
//---------------------------------------------------------------------------//

typedef TCT_NameList_c< TC_Name_c > TOS_DisplayNameList_t;

typedef TCT_NameList_c< TC_NameFile_c > TOS_EchoFileNameList_t;

//---------------------------------------------------------------------------//
// Define execute option constants and typedefs
//---------------------------------------------------------------------------//

enum TOS_ExecuteToolMask_e
{
   TOS_EXECUTE_TOOL_UNDEFINED = 0x00,
   TOS_EXECUTE_TOOL_NONE      = 0x01,
   TOS_EXECUTE_TOOL_PACK      = 0x02,
   TOS_EXECUTE_TOOL_PLACE     = 0x04,
   TOS_EXECUTE_TOOL_ROUTE     = 0x08,
   TOS_EXECUTE_TOOL_ANY       = 0x0E,
   TOS_EXECUTE_TOOL_ALL       = 0x0E
};
typedef enum TOS_ExecuteToolMask_e TOS_ExecuteToolMask_t;
typedef enum TOS_ExecuteToolMask_e TOS_ExecuteToolMode_t;

#endif
