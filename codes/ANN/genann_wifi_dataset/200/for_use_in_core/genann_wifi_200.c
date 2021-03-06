#include <stdio.h>
#include <stdlib.h>
//#include "genann.h"



#ifndef GENANN_H
#define GENANN_H


#ifdef __cplusplus
extern "C" {
#endif


#include <assert.h>
#include <errno.h>
#include <math.h>
#include <string.h>


#define LOOKUP_SIZE 1421





//const char *save_name = "example/xor.ann";

//static int init_array[4] = {2,1,2,1}; //input ,hidden(layer num), hidden2 (neurons in one layer), output


//changeable variables

#define inputs_g 7
#define hidden_layers_g 1
#define hidden_g  4
#define outputs_g  2

//#define print_en

static int weights [42]  =
{	-864	,
	-1456	,
	-248	,
	-1557	,
	-1875	,
	-2073	,
	-216	,
	-247	,
	-2205	,
	-11695	,
	2130	,
	4365	,
	-9979	,
	5583	,
	-7873	,
	-6158	,
	1673	,
	2406	,
	374	,
	1864	,
	2892	,
	2238	,
	450	,
	636	,
	-1286	,
	1597	,
	572	,
	-7458	,
	1429	,
	-19926	,
	3649	,
	3229	,
	283	,
	1309	,
	-2842	,
	-2262	,
	7269	,
	1896	,
	102	,
	6765	,
	205	,
	4541	};


static const int input[200][4] = {
{	32	,	28	,	31	,	33	,	36	,	41	,	41	},
{	34	,	29	,	31	,	33	,	36	,	43	,	43	},
{	32	,	30	,	30	,	34	,	38	,	43	,	43	},
{	31	,	30	,	34	,	31	,	39	,	46	,	40	},
{	32	,	33	,	30	,	32	,	39	,	41	,	44	},
{	32	,	28	,	32	,	33	,	38	,	45	,	42	},
{	33	,	31	,	33	,	34	,	35	,	44	,	43	},
{	31	,	32	,	29	,	33	,	37	,	44	,	41	},
{	33	,	30	,	30	,	32	,	38	,	44	,	41	},
{	30	,	29	,	30	,	31	,	37	,	43	,	45	},
{	31	,	30	,	32	,	32	,	35	,	43	,	43	},
{	32	,	30	,	32	,	33	,	36	,	43	,	46	},
{	33	,	30	,	33	,	33	,	34	,	41	,	43	},
{	32	,	28	,	32	,	33	,	36	,	41	,	45	},
{	34	,	30	,	33	,	33	,	38	,	44	,	44	},
{	32	,	29	,	34	,	33	,	40	,	44	,	45	},
{	33	,	30	,	32	,	34	,	34	,	49	,	42	},
{	33	,	31	,	32	,	34	,	39	,	44	,	45	},
{	33	,	29	,	33	,	35	,	39	,	43	,	43	},
{	34	,	29	,	32	,	36	,	38	,	45	,	44	},
{	33	,	31	,	31	,	33	,	39	,	43	,	43	},
{	31	,	27	,	30	,	31	,	37	,	44	,	42	},
{	33	,	27	,	30	,	31	,	35	,	43	,	42	},
{	33	,	28	,	32	,	33	,	34	,	43	,	46	},
{	32	,	29	,	30	,	34	,	36	,	41	,	47	},
{	32	,	29	,	31	,	33	,	38	,	41	,	45	},
{	32	,	29	,	31	,	34	,	34	,	42	,	43	},
{	34	,	32	,	34	,	32	,	37	,	44	,	43	},
{	35	,	31	,	34	,	33	,	41	,	45	,	42	},
{	34	,	30	,	31	,	33	,	40	,	49	,	41	},
{	33	,	30	,	32	,	34	,	39	,	44	,	43	},
{	33	,	30	,	33	,	34	,	38	,	45	,	43	},
{	34	,	30	,	31	,	33	,	36	,	46	,	43	},
{	35	,	31	,	31	,	31	,	38	,	43	,	43	},
{	34	,	29	,	33	,	33	,	38	,	44	,	41	},
{	33	,	31	,	32	,	34	,	37	,	45	,	42	},
{	34	,	29	,	33	,	34	,	42	,	45	,	44	},
{	33	,	29	,	31	,	34	,	39	,	44	,	46	},
{	33	,	29	,	32	,	35	,	41	,	45	,	46	},
{	33	,	28	,	32	,	36	,	39	,	45	,	43	},
{	32	,	30	,	33	,	35	,	43	,	46	,	45	},
{	32	,	28	,	32	,	35	,	40	,	46	,	43	},
{	34	,	29	,	32	,	34	,	39	,	45	,	43	},
{	34	,	28	,	33	,	34	,	41	,	49	,	45	},
{	33	,	35	,	32	,	35	,	40	,	45	,	44	},
{	34	,	29	,	31	,	34	,	39	,	46	,	44	},
{	31	,	29	,	31	,	34	,	35	,	43	,	44	},
{	32	,	29	,	33	,	34	,	38	,	46	,	47	},
{	31	,	29	,	29	,	33	,	35	,	41	,	46	},
{	32	,	26	,	29	,	34	,	34	,	43	,	41	},
{	20	,	25	,	25	,	26	,	33	,	38	,	40	},
{	19	,	26	,	28	,	22	,	33	,	36	,	38	},
{	19	,	26	,	27	,	23	,	34	,	36	,	38	},
{	20	,	28	,	24	,	24	,	32	,	38	,	40	},
{	19	,	28	,	27	,	20	,	35	,	38	,	36	},
{	22	,	29	,	25	,	23	,	36	,	34	,	37	},
{	20	,	27	,	25	,	20	,	30	,	35	,	37	},
{	19	,	29	,	30	,	18	,	33	,	37	,	34	},
{	19	,	32	,	31	,	22	,	32	,	38	,	38	},
{	18	,	28	,	29	,	19	,	33	,	35	,	36	},
{	10	,	32	,	31	,	17	,	35	,	37	,	36	},
{	19	,	29	,	28	,	18	,	34	,	35	,	37	},
{	17	,	29	,	30	,	20	,	38	,	38	,	37	},
{	9	,	30	,	28	,	18	,	37	,	36	,	33	},
{	10	,	28	,	28	,	18	,	31	,	40	,	36	},
{	17	,	27	,	28	,	20	,	31	,	40	,	37	},
{	9	,	30	,	28	,	18	,	32	,	35	,	38	},
{	7	,	30	,	30	,	18	,	33	,	37	,	37	},
{	9	,	30	,	30	,	8	,	34	,	38	,	38	},
{	9	,	32	,	33	,	10	,	40	,	37	,	36	},
{	7	,	30	,	32	,	8	,	40	,	38	,	36	},
{	6	,	32	,	33	,	8	,	37	,	37	,	37	},
{	6	,	30	,	32	,	9	,	35	,	37	,	37	},
{	6	,	30	,	34	,	7	,	37	,	37	,	35	},
{	6	,	32	,	32	,	9	,	35	,	36	,	37	},
{	8	,	32	,	33	,	13	,	44	,	36	,	37	},
{	13	,	30	,	28	,	19	,	31	,	38	,	40	},
{	20	,	29	,	33	,	20	,	37	,	36	,	40	},
{	19	,	27	,	28	,	18	,	36	,	32	,	34	},
{	19	,	28	,	28	,	19	,	38	,	36	,	38	},
{	19	,	31	,	29	,	20	,	39	,	33	,	34	},
{	20	,	29	,	32	,	21	,	37	,	35	,	35	},
{	22	,	30	,	32	,	20	,	37	,	33	,	32	},
{	22	,	29	,	32	,	19	,	40	,	36	,	36	},
{	23	,	29	,	32	,	23	,	40	,	38	,	33	},
{	22	,	29	,	32	,	20	,	38	,	35	,	32	},
{	21	,	29	,	32	,	20	,	38	,	35	,	34	},
{	22	,	29	,	31	,	20	,	38	,	33	,	34	},
{	23	,	29	,	31	,	20	,	37	,	35	,	34	},
{	20	,	30	,	33	,	24	,	38	,	34	,	33	},
{	20	,	32	,	34	,	20	,	38	,	35	,	35	},
{	20	,	28	,	29	,	17	,	43	,	35	,	33	},
{	18	,	30	,	29	,	18	,	34	,	33	,	39	},
{	18	,	30	,	29	,	9	,	35	,	35	,	38	},
{	8	,	30	,	32	,	7	,	35	,	38	,	43	},
{	17	,	29	,	27	,	17	,	32	,	39	,	38	},
{	19	,	27	,	28	,	18	,	31	,	39	,	40	},
{	21	,	28	,	26	,	18	,	38	,	34	,	41	},
{	19	,	26	,	32	,	19	,	36	,	39	,	39	},
{	22	,	27	,	27	,	19	,	32	,	38	,	37	},
{	25	,	28	,	24	,	25	,	29	,	39	,	43	},
{	24	,	29	,	26	,	22	,	33	,	40	,	40	},
{	24	,	27	,	28	,	24	,	31	,	39	,	42	},
{	25	,	28	,	27	,	24	,	31	,	40	,	39	},
{	24	,	29	,	26	,	22	,	34	,	39	,	38	},
{	25	,	31	,	29	,	23	,	31	,	41	,	39	},
{	23	,	28	,	30	,	23	,	33	,	43	,	43	},
{	26	,	28	,	27	,	25	,	32	,	40	,	44	},
{	23	,	24	,	27	,	25	,	30	,	40	,	39	},
{	23	,	29	,	27	,	24	,	30	,	40	,	40	},
{	25	,	23	,	25	,	24	,	31	,	40	,	43	},
{	25	,	25	,	24	,	25	,	30	,	40	,	45	},
{	25	,	27	,	25	,	27	,	31	,	39	,	41	},
{	26	,	27	,	28	,	28	,	30	,	37	,	39	},
{	24	,	28	,	25	,	26	,	30	,	41	,	37	},
{	27	,	29	,	27	,	27	,	31	,	39	,	38	},
{	24	,	27	,	25	,	30	,	32	,	39	,	40	},
{	26	,	27	,	25	,	26	,	32	,	43	,	45	},
{	27	,	26	,	24	,	25	,	31	,	41	,	40	},
{	27	,	27	,	26	,	25	,	33	,	41	,	41	},
{	23	,	28	,	27	,	26	,	31	,	40	,	40	},
{	24	,	29	,	25	,	28	,	32	,	38	,	37	},
{	24	,	24	,	26	,	28	,	31	,	39	,	39	},
{	25	,	25	,	25	,	23	,	32	,	40	,	39	},
{	24	,	26	,	28	,	25	,	30	,	39	,	40	},
{	26	,	25	,	26	,	25	,	32	,	40	,	43	},
{	24	,	24	,	26	,	26	,	30	,	37	,	40	},
{	24	,	26	,	27	,	25	,	32	,	38	,	41	},
{	25	,	26	,	27	,	25	,	32	,	39	,	42	},
{	23	,	28	,	28	,	23	,	34	,	40	,	39	},
{	23	,	29	,	27	,	24	,	32	,	39	,	38	},
{	26	,	26	,	30	,	23	,	30	,	40	,	41	},
{	27	,	28	,	27	,	27	,	31	,	45	,	43	},
{	25	,	29	,	27	,	25	,	33	,	40	,	45	},
{	26	,	26	,	27	,	27	,	34	,	45	,	43	},
{	26	,	31	,	27	,	26	,	32	,	44	,	40	},
{	26	,	26	,	27	,	27	,	30	,	44	,	43	},
{	25	,	34	,	24	,	28	,	32	,	40	,	39	},
{	24	,	26	,	27	,	26	,	32	,	40	,	39	},
{	26	,	27	,	27	,	25	,	32	,	43	,	40	},
{	26	,	27	,	27	,	27	,	31	,	43	,	39	},
{	27	,	27	,	28	,	26	,	31	,	44	,	39	},
{	26	,	27	,	27	,	26	,	32	,	44	,	39	},
{	26	,	27	,	28	,	25	,	31	,	42	,	40	},
{	24	,	28	,	27	,	26	,	32	,	41	,	44	},
{	26	,	29	,	27	,	28	,	31	,	44	,	41	},
{	25	,	27	,	26	,	28	,	30	,	43	,	37	},
{	25	,	27	,	25	,	26	,	33	,	39	,	41	},
{	23	,	24	,	24	,	25	,	33	,	40	,	43	},
{	26	,	27	,	22	,	26	,	28	,	40	,	40	},
{	30	,	26	,	29	,	30	,	25	,	44	,	45	},
{	30	,	27	,	30	,	30	,	27	,	44	,	44	},
{	29	,	26	,	28	,	31	,	26	,	47	,	43	},
{	28	,	26	,	22	,	30	,	24	,	42	,	45	},
{	28	,	26	,	23	,	30	,	27	,	45	,	43	},
{	28	,	29	,	24	,	30	,	26	,	43	,	43	},
{	32	,	29	,	26	,	30	,	26	,	45	,	48	},
{	29	,	31	,	27	,	30	,	26	,	44	,	45	},
{	29	,	31	,	26	,	31	,	27	,	43	,	45	},
{	29	,	29	,	26	,	30	,	27	,	43	,	45	},
{	29	,	30	,	25	,	31	,	27	,	43	,	45	},
{	29	,	31	,	28	,	30	,	27	,	44	,	44	},
{	29	,	27	,	26	,	31	,	27	,	43	,	45	},
{	28	,	28	,	24	,	27	,	25	,	41	,	40	},
{	29	,	28	,	28	,	27	,	25	,	39	,	40	},
{	32	,	27	,	25	,	28	,	25	,	43	,	40	},
{	29	,	28	,	27	,	30	,	26	,	41	,	43	},
{	30	,	30	,	26	,	30	,	26	,	44	,	44	},
{	29	,	28	,	29	,	30	,	24	,	43	,	43	},
{	30	,	29	,	27	,	29	,	28	,	43	,	44	},
{	30	,	30	,	26	,	30	,	27	,	44	,	44	},
{	30	,	28	,	27	,	30	,	25	,	43	,	43	},
{	29	,	28	,	28	,	31	,	26	,	43	,	43	},
{	29	,	30	,	28	,	30	,	25	,	44	,	42	},
{	29	,	29	,	27	,	29	,	28	,	43	,	44	},
{	28	,	28	,	24	,	30	,	28	,	43	,	43	},
{	26	,	31	,	24	,	30	,	26	,	40	,	40	},
{	27	,	29	,	25	,	31	,	27	,	42	,	41	},
{	28	,	27	,	26	,	31	,	28	,	43	,	44	},
{	29	,	28	,	26	,	33	,	27	,	44	,	43	},
{	29	,	27	,	25	,	30	,	24	,	44	,	46	},
{	28	,	24	,	25	,	31	,	28	,	44	,	46	},
{	30	,	29	,	25	,	30	,	25	,	45	,	40	},
{	32	,	28	,	26	,	37	,	27	,	45	,	40	},
{	31	,	31	,	25	,	33	,	24	,	47	,	40	},
{	32	,	29	,	27	,	32	,	24	,	45	,	46	},
{	32	,	30	,	26	,	31	,	26	,	45	,	46	},
{	32	,	28	,	27	,	30	,	25	,	45	,	45	},
{	31	,	29	,	27	,	32	,	24	,	45	,	41	},
{	32	,	29	,	26	,	32	,	26	,	45	,	47	},
{	32	,	29	,	25	,	33	,	25	,	46	,	43	},
{	33	,	29	,	28	,	32	,	26	,	46	,	44	},
{	31	,	28	,	27	,	35	,	27	,	43	,	45	},
{	31	,	31	,	25	,	32	,	26	,	43	,	45	},
{	30	,	30	,	26	,	32	,	27	,	44	,	44	},
{	31	,	32	,	26	,	35	,	24	,	44	,	44	},
{	32	,	29	,	27	,	33	,	24	,	47	,	44	},
{	32	,	27	,	27	,	33	,	26	,	47	,	45	},
{	32	,	29	,	29	,	35	,	25	,	47	,	44	},
{	35	,	30	,	28	,	32	,	23	,	45	,	48	} };





static const int sigmoid_dom_min = -0x58A;
static const int sigmoid_dom_max = 0x58A;

//non changable variables
#if hidden_layers_g
#define  hidden_weights ((inputs_g+1) * hidden_g + (hidden_layers_g-1) * (hidden_g+1) * hidden_g)
#define output_weights ((hidden_g+1) * outputs_g)
#else
#define  hidden_weights 0
#define output_weights ((inputs_g+1) * outputs_g)
#endif

#define total_weights_g ((hidden_weights + output_weights))//9
#define total_neurons ((inputs_g + hidden_g * hidden_layers_g + outputs_g))
#define size  (sizeof(genann) + sizeof(int) * (total_weights_g + total_neurons + (total_neurons - inputs_g)))
//<<8 https://www.rapidtables.com/convert/number/decimal-to-hex.html?x=-6.029
//https://www.rapidtables.com/convert/number/hex-to-decimal.html?x=1c6
// turn float to hex and shift left 8 bits (*256)







//static const int hidden_weights = hidden_layers ? (inputs+1) * hidden + (hidden_layers-1) * (hidden+1) * hidden : 0;//6
//static const int output_weights = (hidden_layers ? (hidden+1) : (inputs+1)) * outputs;//3
//static const int total_weights = (hidden_weights + output_weights);//9

//static const int total_neurons = (inputs + hidden * hidden_layers + outputs);

/* Allocate extra size for weights, outputs, and deltas. */
//static const int size = sizeof(genann) + sizeof(int) * (total_weights + total_neurons + (total_neurons - inputs));
//static const genann *ret = malloc(size);



// -5.5390625 -(0x5.8A)	low limit  altý 0.00390625     (0x0.01)    den küçük
//  5.5390625  (0x5.8A)   up limit  üstü 1-0.00390625 = 0.99609375  den büyük
//  0.0078125  (0x0.02) is step size
static  int lookup [LOOKUP_SIZE]= {0 , 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 39, 40, 40, 40, 41, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 44, 44, 44, 44, 45, 45, 45, 46, 46, 46, 46, 47, 47, 47, 48, 48, 48, 49, 49, 49, 50, 50, 50, 51, 51, 51, 51, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 57, 57, 57, 58, 58, 58, 59, 59, 59, 60, 60, 60, 61, 61, 62, 62, 62, 63, 63, 63, 64, 64, 64, 65, 65, 66, 66, 66, 67, 67, 68, 68, 68, 69, 69, 70, 70, 70, 71, 71, 72, 72, 72, 73, 73, 74, 74, 74, 75, 75, 76, 76, 76, 77, 77, 78, 78, 79, 79, 79, 80, 80, 81, 81, 82, 82, 83, 83, 83, 84, 84, 85, 85, 86, 86, 86, 87, 87, 88, 88, 89, 89, 90, 90, 91, 91, 91, 92, 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99, 99, 99, 100, 100, 101, 101, 102, 102, 103, 103, 104, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112, 113, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 126, 126, 127, 127, 128, 128, 128, 129, 129, 130, 130, 131, 131, 132, 132, 133, 133, 134, 134, 135, 135, 136, 136, 137, 137, 138, 138, 139, 139, 140, 140, 141, 141, 142, 142, 143, 143, 144, 144, 145, 145, 146, 146, 147, 147, 148, 148, 149, 149, 150, 150, 151, 151, 152, 152, 153, 153, 154, 154, 155, 155, 156, 156, 156, 157, 157, 158, 158, 159, 159, 160, 160, 161, 161, 162, 162, 163, 163, 164, 164, 164, 165, 165, 166, 166, 167, 167, 168, 168, 169, 169, 169, 170, 170, 171, 171, 172, 172, 172, 173, 173, 174, 174, 175, 175, 176, 176, 176, 177, 177, 178, 178, 179, 179, 179, 180, 180, 181, 181, 181, 182, 182, 183, 183, 183, 184, 184, 185, 185, 185, 186, 186, 187, 187, 187, 188, 188, 189, 189, 189, 190, 190, 191, 191, 191, 192, 192, 192, 193, 193, 193, 194, 194, 195, 195, 195, 196, 196, 196, 197, 197, 197, 198, 198, 198, 199, 199, 200, 200, 200, 201, 201, 201, 202, 202, 202, 203, 203, 203, 204, 204, 204, 204, 205, 205, 205, 206, 206, 206, 207, 207, 207, 208, 208, 208, 209, 209, 209, 209, 210, 210, 210, 211, 211, 211, 211, 212, 212, 212, 213, 213, 213, 213, 214, 214, 214, 214, 215, 215, 215, 216, 216, 216, 216, 217, 217, 217, 217, 218, 218, 218, 218, 219, 219, 219, 219, 220, 220, 220, 220, 221, 221, 221, 221, 221, 222, 222, 222, 222, 223, 223, 223, 223, 223, 224, 224, 224, 224, 225, 225, 225, 225, 225, 226, 226, 226, 226, 226, 227, 227, 227, 227, 227, 228, 228, 228, 228, 228, 229, 229, 229, 229, 229, 229, 230, 230, 230, 230, 230, 231, 231, 231, 231, 231, 231, 232, 232, 232, 232, 232, 232, 233, 233, 233, 233, 233, 233, 234, 234, 234, 234, 234, 234, 234, 235, 235, 235, 235, 235, 235, 236, 236, 236, 236, 236, 236, 236, 236, 237, 237, 237, 237, 237, 237, 237, 238, 238, 238, 238, 238, 238, 238, 238, 239, 239, 239, 239, 239, 239, 239, 239, 240, 240, 240, 240, 240, 240, 240, 240, 240, 241, 241, 241, 241, 241, 241, 241, 241, 241, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254,256}
;

#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#define unused          __attribute__((unused))
#else
#define likely(x)       x
#define unlikely(x)     x
#define unused
#pragma warning(disable : 4996) /* For fscanf */
#endif

static int outputs_a[total_neurons] ;


typedef struct _genann {
    /* How many inputs, outputs, and hidden neurons. */
    int inputs, hidden_layers, hidden, outputs;

    /* Which activation function to use for hidden neurons. Default: gennann_act_sigmoid_cached*/
    //genann_actfun activation_hidden;

    /* Which activation function to use for output. Default: gennann_act_sigmoid_cached*/
   // genann_actfun activation_output;

    /* Total number of weights, and size of weights buffer. */
    int total_weights;

    /* Total number of neurons + inputs and size of output buffer. */
    //int total_neurons;

    /* All weights (total_weights long). */
    int *weight;

    /* Stores input array and output of each neuron (total_neurons long). */
    int *output;

    /* Stores delta of each hidden and output neuron (total_neurons - inputs long). */
   // int *delta;

} genann;


#ifdef __cplusplus
}
#endif

#endif /*GENANN_H*/
static genann ann [1] = {{inputs_g,hidden_layers_g,hidden_g,outputs_g,total_weights_g,weights,outputs_a }};

/*****
genann *genann_init( int * weights) {
    //if (hidden_layers < 0) return 0;
    //if (inputs < 1) return 0;
    //if (outputs < 1) return 0;
    //if (hidden_layers > 0 && hidden < 1) return 0;

    //2 1 2 1

    //if (!ret) return 0;

    ret->inputs = inputs_g;
    ret->hidden_layers = hidden_layers_g;
    ret->hidden = hidden_g;
    ret->outputs = outputs_g;

    ret->total_weights = total_weights_g;
    //ret->total_neurons = total_neurons;

    // Set pointers.
    //ret->weight = (int*)((char*)ret + sizeof(genann));
    ret->weight = weights;

    ret->output = ret->weight + ret->total_weights;
    //ret->delta = ret->output + ret->total_neurons;

    //genann_randomize(ret);

    //genann_init_sigmoid_lookup(ret);

    return ret;
}
**/




/*   int  output[200][2] =   {	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	};


int predicted[200][2]= {
{	1,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	1	}	,
{	1,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	1	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	}; */

 int genann_activation( int a) {
    //assert(!isnan(a));
    a = a >> 8;
    if (a < sigmoid_dom_min) return lookup[0];
    if (a > sigmoid_dom_max) return lookup[LOOKUP_SIZE - 1];

    int  j = (a-sigmoid_dom_min)/2 + 1;

    /* Because floating point... */
    //if (unlikely(j >= LOOKUP_SIZE)) return lookup[LOOKUP_SIZE - 1];

    return lookup[j];
}

/*
void genann_free(genann *ann) {
    // The weight, output, and delta pointers go to the same buffer.
    free(ann);
}*/



int const *genann_run(genann const *ann, int const *inputs) {
    int const *w = ann->weight;
    int *o = ann->output + ann->inputs;
    int const *i = ann->output;

    /* Copy the inputs to the scratch area, where we also store each neuron's
     * output, for consistency. This way the first layer isn't a special case. */
    memcpy(ann->output, inputs, sizeof(int) * ann->inputs);

    int h, j, k;

    if (!ann->hidden_layers) {//no hidden layers
        int *ret = o;
        for (j = 0; j < ann->outputs; ++j) {
            int sum = *w++ * -1;
            sum = sum * 256;
            for (k = 0; k < ann->inputs; ++k) {
                sum += *w++ * i[k];
            }
            *o++ = genann_activation( sum);
        }
        return ret;
    }

    /* Figure input layer */
    for (j = 0; j < ann->hidden; ++j) {
        int sum = *w++ * -1;
            sum = sum * 256;
        for (k = 0; k < ann->inputs; ++k) {
           //printf("in_pre_o w= %d i = %d\n", *w , i[k]);

            sum += *w++ * i[k];

            //printf("in_pre %d\n", sum);

        }
        *o++ = genann_activation( sum);
        //printf("in %d %d\n",  genann_activation(  sum), sum);

                        //printf("in %d\n",  genann_activation( sum));

    }

    i += ann->inputs;

    /* Figure hidden layers, if any. */
    for (h = 1; h < ann->hidden_layers; ++h) {
        for (j = 0; j < ann->hidden; ++j) {
            int sum = *w++ * -1;
            sum = sum * 256;
            for (k = 0; k < ann->hidden; ++k) {
                sum += *w++ * i[k];
            }
           *o++ = genann_activation( sum);
           // printf("hid %d %d\n",  genann_activation(  sum), sum);

        }

        i += ann->hidden;
    }
    //*o = *o << 20;
    int const *ret = o;

    /* Figure output layer. */
    for (j = 0; j < ann->outputs; ++j) {
        int sum = *w++ * -1;
            sum = sum * 256;
        for (k = 0; k < ann->hidden; ++k) {
           //printf("out_pre_o w= %d i = %d\n", *w , i[k]);

            sum += *w++ * i[k];
        //printf("out_pre %d\n", sum);
        }
        *o++ = genann_activation( sum);

        //printf("out %d %d\n",  genann_activation(  sum), sum);

        //printf("out %d\n",  genann_activation(sum));
    }

    /* Sanity check that we used all weights and wrote all outputs. */
    //assert(w - ann->weight == ann->total_weights);
    //assert(o - ann->output == ann->total_neurons);

    return ret;
}




int main(int argc, char *argv[])
{
//ret = malloc(size);
    /*printf("GENANN example 3.\n");
    printf("Load a saved ANN to solve the XOR function.\n");


    FILE *saved = fopen(save_name, "r");
    if (!saved) {
        printf("Couldn't open file: %s\n", save_name);
        exit(1);
    }

    genann *ann = genann_read(saved);
    fclose(saved);

    if (!ann) {
        printf("Error loading ANN from file: %s.", save_name);
        exit(1);
    } */
        //int inputs, int hidden_layers, int hidden, int outputs, int * weights)
    //genann *ann = genann_init(weights);
          // printf("abababa w= %d \n", ann->weight[4]) ;


    /* Input data for the XOR function. */

    /* Run the network and see what it predicts. */
    //printf("Output for [%d, %d] is %d.\n", input[0][0], input[0][1], *genann_run(ann, input[0]));
    //printf("Output for [%d, %d] is %d.\n", input[1][0], input[1][1], *genann_run(ann, input[1]));
    //printf("Output for [%d, %d] is %d.\n", input[2][0], input[2][1], *genann_run(ann, input[2]));
    //printf("Output for [%d, %d] is %d.\n", input[3][0], input[3][1], *genann_run(ann, input[3]));

 /*   volatile int results [50][2];
    int i;
	for (i = 0; i<20; i++){
		results[i] = *genann_run(ann, input[i]);
		printf("Output for the %d. result is %d\n", i+1,results[i]);
	}
*/
    volatile static int results [200][2];
    volatile static int real_results [200];

	for (int j = 0; j < 200; j++) {
           int const * result  = genann_run(ann, input[j]);
        results[j][0] = *result++;
        results[j][1] = *result;
        if (results[j][0] <128 && results[j][1] <128)
            real_results[j] = 1;
        else if (results[j][0] <128 && results[j][1] >= 128)
            real_results[j] = 2;
        else if (results[j][0] >= 128 && results[j][1] <128)
            real_results[j] = 3;
        else if (results[j][0] >= 128 && results[j][1] >=128)
            real_results[j] = 4;
        else real_results[j] = 0;
		#ifdef print_en
			printf("Output of input [%d,%d,%d,%d] output [%d %d] predicted [%d %d] is [%d %d] ",input[j][0],input[j][1],input[j][2],input[j][3],output[j][0], output[j][1], predicted[j][0],predicted[j][1], results[j][0],results[j][1]);
			printf("%d\n", real_results[j]);
		 #endif // print_en
		}

/*    results[0] = *genann_run(ann, input[0]);
    results[1] = *genann_run(ann, input[1]);
    results[2] =  *genann_run(ann, input[2]);
    results[3] = *genann_run(ann, input[3]);*/

    //printf("%d",results[1]);
/*
	*genann_run(ann, input[0]);//0
	*genann_run(ann, input[1]);//1
	*genann_run(ann, input[2]);//1
	*genann_run(ann, input[3]);//0 */

    //genann_free(ann);
    return 0;
}
