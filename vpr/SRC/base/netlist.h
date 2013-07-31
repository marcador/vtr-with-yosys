/* 
 * This file contains the netlist data structures and associated functions that 
 * manipulate them.
 *
 *
 *
 */

#ifndef NETLIST_H
#define NETLIST_H

#include "vpr_types.h"
#include <vector>
using namespace std;

typedef struct s_net_nodes{
	int block;
	int block_port;
	int block_pin;

	s_net_nodes(){
		block = block_port = block_pin = 0;
	}
}t_net_nodes;

typedef struct s_vnet{
	char* name;
	unsigned int is_routed    : 1;
	unsigned int is_fixed     : 1;
	unsigned int is_global    : 1;
	unsigned int is_const_gen : 1;
	vector<t_net_nodes> nodes;
	t_net_power * net_power;

	s_vnet(){
		name = NULL;
		is_routed = is_fixed = is_global = is_const_gen = 0;
		net_power = NULL;
	}
}t_vnet;

typedef struct s_netlist{
	//vector<t_blocks> blocks;
	vector<t_vnet>  nets;

}t_netlist;

void load_global_net_from_array(INP t_net* net_arr,
	INP int num_net_arr, OUTP t_netlist* g_nlist);

void echo_global_nlist_net(INP t_netlist* g_nlist);
#endif