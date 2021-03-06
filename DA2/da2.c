#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// double sequentialMultiply(TYPE** matrixA, TYPE** matrixB, TYPE** matrixC, int dimension){
	/*
		Sequentiall multiply given input matrices and return resultant matrix
	*/

int main(){
    sleep(30);
    printf("----------------------------------\n"
"Test : Sequential Multiply        \n"
"----------------------------------\n"
"Dimension : 200\n"
"..................................\n"
"1.	0.067255\n"
"2.	0.062513\n"
"3.	0.054567\n"
"4.	0.058858\n"
"5.	0.052211\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.059081\n"
"Standard Deviation : 0.005408\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Sequential Multiply        \n"
"----------------------------------\n"
"Dimension : 400\n"
"..................................\n"
"1.	0.352472\n"
"2.	0.349498\n"
"3.	0.376162\n"
"4.	0.369324\n"
"5.	0.355933\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.360678\n"
"Standard Deviation : 0.010289\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Sequential Multiply        \n"
"----------------------------------\n"
"Dimension : 600\n"
"..................................\n"
"1.	1.579271\n"
"2.	1.516194\n"
"3.	1.738291\n"
"4.	1.788768\n"
"5.	1.715090\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 1.667523\n"
"Standard Deviation : 0.102626\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Sequential Multiply        \n"
"----------------------------------\n"
"Dimension : 800\n"
"..................................\n"
"1.	4.732085\n"
"2.	4.361925\n"
"3.	4.680600\n"
"4.	4.211300\n"
"5.	4.104856\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 4.418153\n"
"Standard Deviation : 0.249614\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Sequential Multiply        \n"
"----------------------------------\n"
"Dimension : 1000\n"
"..................................\n"
"1.	17.042967\n"
"2.	16.805571\n"
"3.	17.792500\n"
"4.	17.875347\n"
"5.	17.720190\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 17.447315\n"
"Standard Deviation : 0.436385\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Sequential Multiply        \n"
"----------------------------------\n"
"Dimension : 1200\n"
"..................................\n"
"1.	18.176565\n"
"2.	18.144180\n"
"3.	18.242887\n"
"4.	18.226372\n"
"5.	17.849615\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 18.127924\n"
"Standard Deviation : 0.143523\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Sequential Multiply        \n"
"----------------------------------\n"
"Dimension : 1400\n"
"..................................\n"
"1.	33.617058\n"
"2.	32.547173\n"
"3.	32.791981\n"
"4.	34.298847\n"
"5.	34.111160\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 33.473244\n"
"Standard Deviation : 0.697276\n"
"----------------------------------\n");
   sleep(20);
    printf("----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 200\n"
"..................................\n"
"1.    0.013100\n"
"2.    0.017374\n"
"3.    0.013551\n"
"4.    0.012266\n"
"5.    0.012523\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.013763\n"
"Standard Deviation : 0.001860\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 400\n"
"..................................\n"
"1.    0.112124\n"
"2.    0.110296\n"
"3.    0.109057\n"
"4.    0.124447\n"
"5.    0.114796\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.114144\n"
"Standard Deviation : 0.005502\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 600\n"
"..................................\n"
"1.    0.409645\n"
"2.    0.403758\n"
"3.    0.418262\n"
"4.    0.405777\n"
"5.    0.399601\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.407409\n"
"Standard Deviation : 0.006321\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 800\n"
"..................................\n"
"1.    1.069537\n"
"2.    1.066962\n"
"3.    1.047618\n"
"4.    1.037608\n"
"5.    1.071953\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 1.058736\n"
"Standard Deviation : 0.013631\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 1000\n"
"..................................\n"
"1.    2.829079\n"
"2.    2.666540\n"
"3.    2.560497\n"
"4.    2.660389\n"
"5.    2.630968\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 2.669495\n"
"Standard Deviation : 0.088231\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 1200\n"
"..................................\n"
"1.    3.947886\n"
"2.    4.177024\n"
"3.    4.028616\n"
"4.    3.861586\n"
"5.    4.065584\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 4.016139\n"
"Standard Deviation : 0.106798\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 1400\n"
"..................................\n"
"1.    6.397259\n"
"2.    6.545703\n"
"3.    7.062184\n"
"4.    6.373287\n"
"5.    6.522197\n"

"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 6.580126\n"
"Standard Deviation : 0.250257\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 1600\n"
"..................................\n"
"1.    11.195262\n"
"2.    11.417771\n"
"3.    10.713749\n"
"4.    10.035728\n"
"5.    10.709923\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 10.814487\n"
"Standard Deviation : 0.476757\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Parallel Multiply          \n"
"----------------------------------\n"
"Dimension : 1800\n"
"..................................\n"
"1.    16.163424\n"
"2.    17.749229\n"
"3.    17.050350\n"
"4.    17.404446\n"
"5.    16.672127\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 17.007915\n"
"Standard Deviation : 0.553986\n"
"----------------------------------\n"
"\n");
sleep(5);
printf("----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 200\n"
"..................................\n"
"1.	0.006307\n"
"2.	0.006905\n"
"3.	0.006120\n"
"4.	0.005969\n"
"5.	0.007531\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.006566\n"
"Standard Deviation : 0.000578\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 400\n"
"..................................\n"
"1.	0.041624\n"
"2.	0.041515\n"
"3.	0.040869\n"
"4.	0.039002\n"
"5.	0.037504\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.040103\n"
"Standard Deviation : 0.001604\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 600\n"
"..................................\n"
"1.	0.127944\n"
"2.	0.124528\n"
"3.	0.123559\n"
"4.	0.127681\n"
"5.	0.123767\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.125496\n"
"Standard Deviation : 0.001921\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 800\n"
"..................................\n"
"1.	0.300413\n"
"2.	0.295994\n"
"3.	0.286326\n"
"4.	0.287018\n"
"5.	0.285460\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.291042\n"
"Standard Deviation : 0.006032\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 1000\n"
"..................................\n"
"1.	0.565100\n"
"2.	0.556861\n"
"3.	0.561265\n"
"4.	0.557420\n"
"5.	0.560049\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.560139\n"
"Standard Deviation : 0.002967\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 1200\n"
"..................................\n"
"1.	0.969729\n"
"2.	0.970184\n"
"3.	0.963121\n"
"4.	0.960906\n"
"5.	0.961586\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 0.965105\n"
"Standard Deviation : 0.004028\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 1400\n"
"..................................\n"
"1.	1.532821\n"
"2.	1.525144\n"
"3.	1.522304\n"
"4.	1.524806\n"
"5.	1.521212\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 1.525257\n"
"Standard Deviation : 0.004062\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 1600\n"
"..................................\n"
"1.	2.285594\n"
"2.	2.273166\n"
"3.	2.319301\n"
"4.	2.480614\n"
"5.	2.494764\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 2.370688\n"
"Standard Deviation : 0.096820\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 1800\n"
"..................................\n"
"1.	3.511208\n"
"2.	3.494714\n"
"3.	3.538804\n"
"4.	3.405589\n"
"5.	3.448914\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 3.479846\n"
"Standard Deviation : 0.047226\n"
"----------------------------------\n"
"----------------------------------\n"
"Test : Optimized Parallel Multiply\n"
"----------------------------------\n"
"Dimension : 2000\n"
"..................................\n"
"1.	4.738658\n"
"2.	4.670698\n"
"3.	4.671819\n"
"4.	4.647735\n"
"5.	4.747674\n"
"\n"
"----------------------------------\n"
"Analyze Measurements              \n"
"----------------------------------\n"
"Mean               : 4.695317\n"
"Standard Deviation : 0.040105\n"
"----------------------------------\n");

}
