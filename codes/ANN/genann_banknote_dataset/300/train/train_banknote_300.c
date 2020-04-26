#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "C:/Users/Tutel/Desktop/genann/genann_robot/genann_robot_c_run/genann.h"
#include "genann.c"
/*
 * GENANN - Minimal C Artificial Neural Network
 *
 * Copyright (c) 2015-2018 Lewis Van Winkle
 *
 * http://CodePlea.com
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgement in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

//#include "genann.h"
void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(int argc, char *argv[])
{
    //printf("GENANN example 1.\n");
    //printf("Train a small ANN to the XOR function using backpropagation.\n");

    /* This will make the neural network initialize differently each run. */
    /* If you don't get a good result, try again for a different result. */
    srand(time(0));

    /* Input and expected out data for the XOR function. */
    const double input[300][4] = {
{	0.0308	,	0.1947	,	0.23635	,	0.2197	},
{	0.27205	,	0.3618	,	0.00545	,	0.3782	},
{	0.015	,	0.00865	,	0.0877	,	0.02445	},
{	0.067	,	0.2066	,	0.23505	,	0.1299	},
{	0.0134	,	0.24935	,	0.2575	,	0.31955	},
{	0.32615	,	0.48005	,	0.01265	,	0.3482	},
{	0.20335	,	0.12475	,	0.03975	,	0.05515	},
{	0.1282	,	0.08525	,	0.0751	,	0.01635	},
{	0.06705	,	0.0958	,	0.00775	,	0.00595	},
{	0.0119	,	0.10435	,	0.1676	,	0.03325	},
{	0.03105	,	0.18385	,	0.20385	,	0.10355	},
{	0.0389	,	0.17005	,	0.17425	,	0.1778	},
{	0.2062	,	0.1895	,	0.03265	,	0.209	},
{	0.3521	,	0.46	,	0.01295	,	0.23415	},
{	0.2473	,	0.17855	,	0.04135	,	0.07475	},
{	0.17675	,	0.0152	,	0.0328	,	0.01475	},
{	0.1033	,	0.00845	,	0.05025	,	0.04145	},
{	0.04435	,	0.1404	,	0.15715	,	0.06015	},
{	0.0547	,	0.11535	,	0.12615	,	0.07225	},
{	0.12225	,	0.0814	,	0.04425	,	0.074	},
{	0.17755	,	0.09475	,	0.0093	,	0.122	},
{	0.11405	,	0.0428	,	0.1359	,	0.0022	},
{	0.18025	,	0.2987	,	0.50455	,	0.0414	},
{	0.25335	,	0.25935	,	0.5213	,	0.04335	},
{	0.196	,	0.2036	,	0.0118	,	0.10575	},
{	0.0565	,	0.09225	,	0.06785	,	0.069	},
{	0.1228	,	0.2278	,	0.32265	,	0.0028	},
{	0.22385	,	0.6515	,	0.85415	,	0.1517	},
{	0.20975	,	0.40905	,	0.60645	,	0.08005	},
{	0.169	,	0.03535	,	0.1266	,	0.0359	},
{	0.1218	,	0.1801	,	0.0708	,	0.1447	},
{	0.0388	,	0.0065	,	0.00155	,	0.01765	},
{	0.1354	,	0.3413	,	0.37665	,	0.0295	},
{	0.22765	,	0.62925	,	0.77205	,	0.0749	},
{	0.19445	,	0.3916	,	0.491	,	0.0237	},
{	0.1254	,	0.01135	,	0.0744	,	0.0603	},
{	0.10825	,	0.15105	,	0.12065	,	0.1212	},
{	0.09485	,	0.17535	,	0.0892	,	0.19245	},
{	0.031	,	0.0279	,	0.01925	,	0.0332	},
{	0.0919	,	0.31505	,	0.2825	,	0.00975	},
{	0.00125	,	0.16995	,	0.2216	,	0.21325	},
{	0.2198	,	0.248	,	0.0324	,	0.27355	},
{	0.1228	,	0.0122	,	0.0702	,	0.0229	},
{	0.131	,	0.34275	,	0.3108	,	0.0311	},
{	0.1483	,	0.51625	,	0.4392	,	0.10565	},
{	0.0357	,	0.2222	,	0.1112	,	0.0249	},
{	0.03	,	0.04995	,	0.1106	,	0.00485	},
{	0.1395	,	0.28565	,	0.29765	,	0.02295	},
{	0.0999	,	0.33035	,	0.24125	,	0.02095	},
{	0.0077	,	0.00585	,	0.0841	,	0.02975	},
{	0.0604	,	0.2037	,	0.23815	,	0.1306	},
{	0.01475	,	0.24425	,	0.25745	,	0.3116	},
{	0.3212	,	0.47655	,	0.0011	,	0.34255	},
{	0.19965	,	0.13105	,	0.0314	,	0.05795	},
{	0.13295	,	0.08025	,	0.0682	,	0.0082	},
{	0.07045	,	0.10625	,	0.00515	,	0.0096	},
{	0.0055	,	0.0987	,	0.1683	,	0.0326	},
{	0.02615	,	0.1822	,	0.2037	,	0.0995	},
{	0.03835	,	0.17295	,	0.172	,	0.17135	},
{	0.19845	,	0.18405	,	0.03	,	0.20065	},
{	0.3518	,	0.46465	,	0.00825	,	0.22695	},
{	0.2472	,	0.165	,	0.05315	,	0.0722	},
{	0.17965	,	0.01145	,	0.0356	,	0.01665	},
{	0.10835	,	0.0062	,	0.0523	,	0.0431	},
{	0.048	,	0.1348	,	0.1561	,	0.0656	},
{	0.054	,	0.10995	,	0.1293	,	0.06375	},
{	0.11635	,	0.0719	,	0.04105	,	0.0643	},
{	0.1862	,	0.09515	,	0.00175	,	0.12545	},
{	0.1286	,	0.0478	,	0.13535	,	0.0083	},
{	0.19645	,	0.30405	,	0.50475	,	0.0507	},
{	0.2647	,	0.2573	,	0.51665	,	0.0559	},
{	0.19475	,	0.20195	,	0.01505	,	0.10915	},
{	0.0612	,	0.0874	,	0.074	,	0.0709	},
{	0.132	,	0.22075	,	0.29915	,	0.00695	},
{	0.23165	,	0.6375	,	0.8358	,	0.1608	},
{	0.2144	,	0.39315	,	0.5919	,	0.09485	},
{	0.16725	,	0.0252	,	0.1316	,	0.02685	},
{	0.0559	,	0.16675	,	0.06725	,	0.09785	},
{	0.02795	,	0.0155	,	0.00915	,	0.0223	},
{	0.07535	,	0.36595	,	0.3949	,	0.0614	},
{	0.1753	,	0.6283	,	0.758	,	0.0376	},
{	0.14745	,	0.41365	,	0.5132	,	0.0581	},
{	0.0801	,	0.01945	,	0.081	,	0.0955	},
{	0.0633	,	0.1409	,	0.1213	,	0.0943	},
{	0.0246	,	0.153	,	0.09175	,	0.1417	},
{	0.03315	,	0.00225	,	0.00935	,	0.0117	},
{	0.036	,	0.3379	,	0.292	,	0.03115	},
{	0.0998	,	0.475	,	0.4841	,	0.0064	},
{	0.04865	,	0.3208	,	0.2801	,	0.0516	},
{	0.00125	,	0.00865	,	0.00565	,	0.06095	},
{	0.0031	,	0.1465	,	0.1773	,	0.13365	},
{	0.27625	,	0.31625	,	0.04485	,	0.3312	},
{	0.0647	,	0.13365	,	0.042	,	0.1016	},
{	0.012	,	0.08915	,	0.10675	,	0.06205	},
{	0.0698	,	0.48345	,	0.47325	,	0.0174	},
{	0.14835	,	0.6643	,	0.6736	,	0.13135	},
{	0.055	,	0.3625	,	0.30065	,	0.0184	},
{	0.0112	,	0.02605	,	0.02015	,	0.06005	},
{	0.0452	,	0.1685	,	0.2249	,	0.1848	},
{	0.14305	,	0.22595	,	0.02905	,	0.2131	},
{	0.05415	,	0.0156	,	0.06405	,	0.0206	},
{	0.0784	,	0.3622	,	0.32765	,	0.00635	},
{	0.1027	,	0.54335	,	0.4746	,	0.07055	},
{	0.0117	,	0.22575	,	0.10595	,	0.0722	},
{	0.07905	,	0.04345	,	0.11565	,	0.0412	},
{	0.07755	,	0.19005	,	0.2457	,	0.1874	},
{	0.20735	,	0.3561	,	0.00415	,	0.32085	},
{	0.1131	,	0.00495	,	0.1406	,	0.0243	},
{	0.08735	,	0.29115	,	0.29345	,	0.0606	},
{	0.04795	,	0.3356	,	0.24925	,	0.0164	},
{	0.06725	,	0.01175	,	0.0939	,	0.06625	},
{	0.11135	,	0.20475	,	0.24015	,	0.10555	},
{	0.06285	,	0.24365	,	0.2643	,	0.2937	},
{	0.26925	,	0.45605	,	0.02095	,	0.2959	},
{	0.1489	,	0.1172	,	0.0263	,	0.02005	},
{	0.07925	,	0.1078	,	0.0854	,	0.04505	},
{	0.0109	,	0.11015	,	0.00475	,	0.0282	},
{	0.0659	,	0.09505	,	0.16555	,	0.00325	},
{	0.07445	,	0.1714	,	0.2015	,	0.07125	},
{	0.00575	,	0.16105	,	0.1715	,	0.14225	},
{	0.1696	,	0.1678	,	0.036	,	0.17615	},
{	0.30815	,	0.43545	,	0.0108	,	0.1817	},
{	0.2039	,	0.14615	,	0.0435	,	0.03265	},
{	0.12945	,	0.01955	,	0.0467	,	0.02145	},
{	0.05055	,	0.0095	,	0.04525	,	0.00015	},
{	0.0033	,	0.12455	,	0.147	,	0.03105	},
{	0.01235	,	0.0968	,	0.12345	,	0.04025	},
{	0.07865	,	0.05315	,	0.0356	,	0.0419	},
{	0.1083	,	0.07965	,	0.00225	,	0.0839	},
{	0.0583	,	0.07115	,	0.1462	,	0.03305	},
{	0.14195	,	0.3315	,	0.5242	,	0.02105	},
{	0.2252	,	0.2906	,	0.5443	,	0.0264	},
{	0.1205	,	0.18715	,	0.0201	,	0.06475	},
{	0.0203	,	0.06745	,	0.0725	,	0.02795	},
{	0.0694	,	0.24385	,	0.32385	,	0.01705	},
{	0.1875	,	0.6729	,	0.87965	,	0.13885	},
{	0.17815	,	0.4191	,	0.61965	,	0.0641	},
{	0.12705	,	0.0329	,	0.1342	,	0.05975	},
{	0.0833	,	0.015	,	0.07115	,	0.0012	},
{	0.1048	,	0.35525	,	0.3309	,	0.01685	},
{	0.1334	,	0.52255	,	0.45565	,	0.0866	},
{	0.0237	,	0.21745	,	0.0995	,	0.03755	},
{	0.05275	,	0.05925	,	0.13205	,	0.0055	},
{	0.0582	,	0.19045	,	0.247	,	0.2045	},
{	0.22385	,	0.3685	,	0.0156	,	0.33875	},
{	0.13665	,	0.02275	,	0.12195	,	0.01085	},
{	0.1143	,	0.2724	,	0.29015	,	0.0441	},
{	0.0812	,	0.3172	,	0.23285	,	0.00845	},
{	0.0254	,	0.02385	,	0.099	,	0.02885	},
{	0.082	,	0.2125	,	0.2451	,	0.1331	},
{	0.13705	,	0.57015	,	0.12695	,	0.27895	},
{	0.1683	,	0.25925	,	0.18465	,	0.0571	},
{	0.22795	,	0.12105	,	0.13205	,	0.0808	},
{	0.2556	,	0.0249	,	0.0314	,	0.0559	},
{	0.16695	,	0.2307	,	0.1991	,	0.01185	},
{	0.2101	,	0.01135	,	0.04805	,	0.0486	},
{	0.17715	,	0.06195	,	0.09985	,	0.1077	},
{	0.11565	,	0.53325	,	0.1764	,	0.23835	},
{	0.0929	,	0.3943	,	0.0832	,	0.0919	},
{	0.1553	,	0.47705	,	0.21265	,	0.20015	},
{	0.1458	,	0.5415	,	0.16715	,	0.2061	},
{	0.1996	,	0.22335	,	0.1865	,	0.00545	},
{	0.0759	,	0.2847	,	0.0047	,	0.0013	},
{	0.16175	,	0.48235	,	0.16035	,	0.1297	},
{	0.2109	,	0.3408	,	0.064	,	0.038	},
{	0.08905	,	0.34585	,	0.0637	,	0.07875	},
{	0.12665	,	0.14565	,	0.0411	,	0.0061	},
{	0.1948	,	0.3708	,	0.0912	,	0.007	},
{	0.1054	,	0.33975	,	0.0085	,	0.0245	},
{	0.1448	,	0.03535	,	0.1145	,	0.0933	},
{	0.04645	,	0.18985	,	0.2321	,	0.01475	},
{	0.1732	,	0.53435	,	0.17035	,	0.20545	},
{	0.20355	,	0.5201	,	0.2086	,	0.2379	},
{	0.07285	,	0.45605	,	0.0871	,	0.2562	},
{	0.07535	,	0.0961	,	0.3573	,	0.04455	},
{	0.04585	,	0.4994	,	0.059	,	0.2613	},
{	0.1497	,	0.36005	,	0.06075	,	0.01605	},
{	0.11715	,	0.64755	,	0.1664	,	0.2971	},
{	0.18905	,	0.1442	,	0.11275	,	0.00785	},
{	0.2334	,	0.06545	,	0.00275	,	0.09545	},
{	0.1733	,	0.05555	,	0.0871	,	0.0669	},
{	0.16345	,	0.21705	,	0.1844	,	0.0149	},
{	0.2565	,	0.4335	,	0.14455	,	0.0754	},
{	0.10065	,	0.30705	,	0.01895	,	0.02845	},
{	0.02165	,	0.27695	,	0.10165	,	0.0202	},
{	0.052	,	0.4699	,	0.04295	,	0.26665	},
{	0.208	,	0.56095	,	0.18065	,	0.20405	},
{	0.2719	,	0.4733	,	0.24705	,	0.196	},
{	0.2516	,	0.4101	,	0.13125	,	0.0517	},
{	0.26205	,	0.5269	,	0.20585	,	0.21395	},
{	0.0103	,	0.461	,	0.1852	,	0.3405	},
{	0.10455	,	0.04715	,	0.22755	,	0.0617	},
{	0.08655	,	0.01735	,	0.2095	,	0.04955	},
{	0.20865	,	0.16665	,	0.0712	,	0.0302	},
{	0.19615	,	0.1623	,	0.17285	,	0.04185	},
{	0.1924	,	0.50765	,	0.1928	,	0.2111	},
{	0.02595	,	0.16315	,	0.15445	,	0.0492	},
{	0.1929	,	0.0392	,	0.05515	,	0.085	},
{	0.08745	,	0.00875	,	0.2591	,	0.0646	},
{	0.18135	,	0.0491	,	0.0344	,	0.0317	},
{	0.13695	,	0.37005	,	0.00355	,	0.1265	},
{	0.2272	,	0.41135	,	0.1208	,	0.07935	},
{	0.08795	,	0.59605	,	0.13375	,	0.1662	},
{	0.25345	,	0.01065	,	0.0101	,	0.06045	},
{	0.17295	,	0.5556	,	0.21015	,	0.25465	},
{	0.09675	,	0.40825	,	0.00115	,	0.1129	},
{	0.1243	,	0.04975	,	0.267	,	0.0077	},
{	0.1211	,	0.22875	,	0.29735	,	0.01075	},
{	0.19735	,	0.1886	,	0.14415	,	0.00095	},
{	0.11315	,	0.2243	,	0.18275	,	0.0306	},
{	0.0678	,	0.21175	,	0.1067	,	0.01605	},
{	0.25225	,	0.1948	,	0.0715	,	0.0431	},
{	0.17745	,	0.4308	,	0.16395	,	0.06	},
{	0.00865	,	0.39345	,	0.0134	,	0.1894	},
{	0.12	,	0.46795	,	0.1678	,	0.1676	},
{	0.24425	,	0.07995	,	0	,	0.082	},
{	0.2096	,	0.16335	,	0.12915	,	0.01085	},
{	0.0558	,	0.43245	,	0.0481	,	0.09055	},
{	0.05115	,	0.34505	,	0.1003	,	0.1356	},
{	0.09015	,	0.59405	,	0.10225	,	0.2636	},
{	0.00585	,	0.3138	,	0.07745	,	0.1237	},
{	0.0285	,	0.0012	,	0.0621	,	0.0281	},
{	0.20275	,	0.1229	,	0.114	,	0.0516	},
{	0.08475	,	0.05325	,	0.44145	,	0.04745	},
{	0.05595	,	0.53635	,	0.10465	,	0.2825	},
{	0.09395	,	0.1235	,	0.12465	,	0.0188	},
{	0.17915	,	0.18985	,	0.17195	,	0.00625	},
{	0.0095	,	0.45645	,	0.18625	,	0.2911	},
{	0.1829	,	0.2843	,	0.08575	,	0.01185	},
{	0.00655	,	0.08885	,	0.41655	,	0.0176	},
{	0.1196	,	0.4899	,	0.1518	,	0.1411	},
{	0.0821	,	0.1507	,	0.0114	,	0.00735	},
{	0.00585	,	0.0789	,	0.4015	,	0.0014	},
{	0.03475	,	0.4308	,	0.09205	,	0.2164	},
{	0.1471	,	0.3705	,	0.04885	,	0.0442	},
{	0.08775	,	0.59725	,	0.1547	,	0.24485	},
{	0.06265	,	0.544	,	0.09655	,	0.21615	},
{	0.1629	,	0.22305	,	0.1901	,	0.0075	},
{	0.09155	,	0.31835	,	0.0018	,	0.00245	},
{	0.2282	,	0.18135	,	0.1434	,	0.01385	},
{	0.1368	,	0.2516	,	0.333	,	0.0289	},
{	0.04645	,	0.18985	,	0.2321	,	0.01475	},
{	0.1983	,	0.5084	,	0.20565	,	0.23025	},
{	0.07285	,	0.0042	,	0.2089	,	0.02955	},
{	0.24135	,	0.1534	,	0.0343	,	0.04035	},
{	0.11705	,	0.6189	,	0.0352	,	0.37915	},
{	0.0929	,	0.3943	,	0.0832	,	0.0919	},
{	0.20725	,	0.36285	,	0.09575	,	0.043	},
{	0.09575	,	0.30405	,	0.01185	,	0.10055	},
{	0.20105	,	0.10955	,	0.1232	,	0.057	},
{	0.2943	,	0.2937	,	0.1408	,	0.015	},
{	0.10445	,	0.5413	,	0.118	,	0.17095	},
{	0.2001	,	0.1797	,	0.17785	,	0.0134	},
{	0.0393	,	0.4783	,	0.1893	,	0.37515	},
{	0.20875	,	0.51305	,	0.19275	,	0.21525	},
{	0.0416	,	0.377	,	0.0325	,	0.04625	},
{	0.24035	,	0.1116	,	0.01315	,	0.07765	},
{	0.2653	,	0.2634	,	0.1445	,	0.02635	},
{	0.128	,	0.4634	,	0.17955	,	0.0678	},
{	0.10525	,	0.3802	,	0.02385	,	0.0923	},
{	0.1086	,	0.0369	,	0.27335	,	0.03615	},
{	0.21445	,	0.45905	,	0.2303	,	0.2163	},
{	0.17575	,	0.50945	,	0.21375	,	0.2489	},
{	0.1307	,	0.4004	,	0.18625	,	0.0653	},
{	0.034	,	0.11625	,	0.2454	,	0.02745	},
{	0.2098	,	0.0372	,	0.0416	,	0.03765	},
{	0.30455	,	0.14835	,	0.0663	,	0.07275	},
{	0.06615	,	0.1648	,	0.0118	,	0.00595	},
{	0.0663	,	0.0516	,	0.2828	,	0.02065	},
{	0.00835	,	0.38135	,	0.0603	,	0.1812	},
{	0.065	,	0.51335	,	0.14765	,	0.29315	},
{	0.1113	,	0.62695	,	0.14715	,	0.17625	},
{	0.12095	,	0.3233	,	0.0378	,	0.0114	},
{	0.0549	,	0.03195	,	0.29945	,	0.0291	},
{	0.2323	,	0.5266	,	0.22925	,	0.2103	},
{	0.018	,	0.20575	,	0.1557	,	0.01855	},
{	0.0678	,	0.16065	,	0.2173	,	0.0393	},
{	0.0285	,	0.0012	,	0.0621	,	0.0281	},
{	0.13235	,	0.50685	,	0.06655	,	0.2735	},
{	0.15605	,	0.15685	,	0.09625	,	0.0187	},
{	0.2747	,	0.07735	,	0.00205	,	0.0964	},
{	0.0669	,	0.0776	,	0.354	,	0.05155	},
{	0.1168	,	0.598	,	0.15415	,	0.27215	},
{	0.11295	,	0.00165	,	0.23675	,	0.01385	},
{	0.02345	,	0.03165	,	0.3692	,	0.01825	},
{	0.13645	,	0.1435	,	0.02555	,	0.02545	},
{	0.1023	,	0.1015	,	0.1088	,	0.00415	},
{	0.06635	,	0.4749	,	0.122	,	0.2634	},
{	0.1945	,	0.1076	,	0.1315	,	0.0552	},
{	0.19995	,	0.0452	,	0.05845	,	0.08445	},
{	0.11975	,	0.4754	,	0.1589	,	0.1504	},
{	0.1635	,	0.3466	,	0.05225	,	0.0117	},
{	0.06965	,	0.0783	,	0.3769	,	0.0392	},
{	0.082	,	0.1774	,	0.0698	,	0.0182	},
{	0.1387	,	0.34285	,	0.05335	,	0.00375	},
{	0.1214	,	0.4691	,	0.16235	,	0.0727	},
{	0.21065	,	0.1403	,	0.10055	,	0.0337	},
{	0.08235	,	0.0241	,	0.2372	,	0.06125	},
{	0.10295	,	0.04965	,	0.26055	,	0.01465	},
{	0.01895	,	0.03545	,	0.03785	,	0.0222	}  };


   double  output[300][2] =   {
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
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	};


int array_index [300] = {	0	,
	1	,
	2	,
	3	,
	4	,
	5	,
	6	,
	7	,
	8	,
	9	,
	10	,
	11	,
	12	,
	13	,
	14	,
	15	,
	16	,
	17	,
	18	,
	19	,
	20	,
	21	,
	22	,
	23	,
	24	,
	25	,
	26	,
	27	,
	28	,
	29	,
	30	,
	31	,
	32	,
	33	,
	34	,
	35	,
	36	,
	37	,
	38	,
	39	,
	40	,
	41	,
	42	,
	43	,
	44	,
	45	,
	46	,
	47	,
	48	,
	49	,
	50	,
	51	,
	52	,
	53	,
	54	,
	55	,
	56	,
	57	,
	58	,
	59	,
	60	,
	61	,
	62	,
	63	,
	64	,
	65	,
	66	,
	67	,
	68	,
	69	,
	70	,
	71	,
	72	,
	73	,
	74	,
	75	,
	76	,
	77	,
	78	,
	79	,
	80	,
	81	,
	82	,
	83	,
	84	,
	85	,
	86	,
	87	,
	88	,
	89	,
	90	,
	91	,
	92	,
	93	,
	94	,
	95	,
	96	,
	97	,
	98	,
	99	,
	100	,
	101	,
	102	,
	103	,
	104	,
	105	,
	106	,
	107	,
	108	,
	109	,
	110	,
	111	,
	112	,
	113	,
	114	,
	115	,
	116	,
	117	,
	118	,
	119	,
	120	,
	121	,
	122	,
	123	,
	124	,
	125	,
	126	,
	127	,
	128	,
	129	,
	130	,
	131	,
	132	,
	133	,
	134	,
	135	,
	136	,
	137	,
	138	,
	139	,
	140	,
	141	,
	142	,
	143	,
	144	,
	145	,
	146	,
	147	,
	148	,
	149	,
	150	,
	151	,
	152	,
	153	,
	154	,
	155	,
	156	,
	157	,
	158	,
	159	,
	160	,
	161	,
	162	,
	163	,
	164	,
	165	,
	166	,
	167	,
	168	,
	169	,
	170	,
	171	,
	172	,
	173	,
	174	,
	175	,
	176	,
	177	,
	178	,
	179	,
	180	,
	181	,
	182	,
	183	,
	184	,
	185	,
	186	,
	187	,
	188	,
	189	,
	190	,
	191	,
	192	,
	193	,
	194	,
	195	,
	196	,
	197	,
	198	,
	199	,
200	,
201	,
202	,
203	,
204	,
205	,
206	,
207	,
208	,
209	,
210	,
211	,
212	,
213	,
214	,
215	,
216	,
217	,
218	,
219	,
220	,
221	,
222	,
223	,
224	,
225	,
226	,
227	,
228	,
229	,
230	,
231	,
232	,
233	,
234	,
235	,
236	,
237	,
238	,
239	,
240	,
241	,
242	,
243	,
244	,
245	,
246	,
247	,
248	,
249	,
250	,
251	,
252	,
253	,
254	,
255	,
256	,
257	,
258	,
259	,
260	,
261	,
262	,
263	,
264	,
265	,
266	,
267	,
268	,
269	,
270	,
271	,
272	,
273	,
274	,
275	,
276	,
277	,
278	,
279	,
280	,
281	,
282	,
283	,
284	,
285	,
286	,
287	,
288	,
289	,
290	,
291	,
292	,
293	,
294	,
295	,
296	,
297	,
298	,
299	};



    int i;
	int j;
	int k;
    /* New network with 2 inputs,
     * 1 hidden layer of 2 neurons,
     * and 1 output. */
    volatile genann *ann = genann_init(4, 1, 2, 2);

    /* Train on the four labeled data points many times. */


    for (i = 0; i < 300; ++i) {
    shuffle(array_index, 300);

		for (j = 0; j < 300; j++) {
		  //  srand(time(NULL));

                //int v  = rand() % 200;
			genann_train(ann, input[array_index[j]], output[array_index[j]],2);
		}
    }
			//printf(" \n ");

        //	genann_train(ann, input[0], output + 0, 3);
    //  genann_train(ann, input[1], output + 1, 3);
    //  genann_train(ann, input[2], output + 2, 3);
    //  genann_train(ann, input[3], output + 3, 3);

    /* Run the network and see what it predicts. */
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[0][0], input[0][1], *genann_run(ann, input[0]));
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[1][0], input[1][1], *genann_run(ann, input[1]));
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[2][0], input[2][1], *genann_run(ann, input[2]));
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[3][0], input[3][1], *genann_run(ann, input[3]));

	for (int j = 0; j < 300; j++) {
            double * result = genann_run(ann, input[j]);

//
			printf("Output of input [%f,%f,%f,%f] for [%f %f] is %1.f ",input[j][0],input[j][1],input[j][2],input[j][3],output[j][0] , output[j][1],  *result++);
			printf("%1.f\n", *result);
		}

//  *genann_run(ann, input[0];
//	*genann_run(ann, input[1];
//	*genann_run(ann, input[2];
//	*genann_run(ann, input[3];
    FILE *robot_weight = fopen("genann.txt", "w");
    genann_write(ann,robot_weight);
    genann_free(ann);
    fclose(robot_weight);

    return 0;
}
