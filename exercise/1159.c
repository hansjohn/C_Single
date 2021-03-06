/* 描述
为了使用圣剑，人类必须使用护符来组成圣剑，并且定期对圣剑进行调整。但是现在最后一个会调整圣剑的人类——威廉·克梅修，已经沉眠。黄金妖精们必须想一个别的办法，于是她们找到了你。

圣剑有正反两个面，每个面有若干个空槽，可以放入任意个护符，但总共要装入个护符。但是有对护符之间有排斥性，放在同一行的话会导致圣剑性能下降。

圣剑下降的性能点数为正面或反面产生的排斥性的最大值。求圣剑下降了多少性能。

以样例输入和输出为例，让护符1和2在同一行，护符3和4在同一行，能取得最优解。此时1和2的排斥性为1303，3和4的排斥性为664，所以答案为1303。

输入
第1行包含2个整数，表示有个护符，对护符之间有排斥性。接下来行，每行3个整数，表示护符和护符之间有排斥性。

输出
1行，包含一个整数，表示求出的圣剑下降性能。

样例输入 
4 6
2 3 7887
2 1 1303
4 1 9177
4 2 2913
1 3 76
4 3 664
样例输出 
1303 */