#include <stdio.h>
#include <stdlib.h>

 typedef struct//规则简化说明：无懈可击只能对自己用，青釭剑一旦装备就成为一种状态，无需发动 
{//对于延时类锦囊牌，无懈可击只能够在判定前使用，而不能够在刚贴上去的时候用 
//藤甲也写进状态里面，而不用发动 
	int num;
	int color;
	int name;//好多地方没有返回值,好多地方缺少了删除操作
	int type;//锦囊牌，装备牌啥的
}Card;//酒杀待会儿加

#define sha 0// 杀 
#define huosha 1//火杀 
#define leisha 2//雷杀 
#define shan 3//闪 
#define tao 4//桃 
#define jiu 5//酒 
#define juedou 6//决斗 
#define wuzhong 7//无中生有 
#define guohe 8//过河拆桥 
#define shunshou 9//顺手牵羊 
#define jiedao 10//借刀杀人 
#define nanman 11//南蛮入侵 
#define wanjian 12//万箭齐发 
#define taoyuan 13//桃园结义 
#define wugu 14//五谷丰登 
#define wuxie 15//无懈可击 
#define huogong 16//火攻 
#define tiesuo 17//铁索连环 
#define lebu 18//乐不思蜀 
#define shandian 19//闪电 
#define bingliang 20//兵粮寸断 
#define cixiong 21//雌雄双股剑 
#define qinglong 22//青龙偃月刀 
#define qinggang 23//青釭剑 
#define zhangba 24//丈八蛇矛 
#define qilin 25//麒麟弓 
#define zhuge 26//诸葛连弩 
#define guanshi 27//贯石斧 
#define fangtian 28//方天画戟 
#define hanbing 29//寒冰剑 
#define guding 30//古锭刀 
#define zhuque 31//朱雀羽扇 
#define bagua 32//八卦阵 
#define renwang 33//仁王盾 
#define tengjia 34//藤甲 
#define baiyin 35//白银狮子 
#define horse1 36//+1马 
#define horse2 37//-1马

#define ST_CHUPAI 0
#define ST_BEISHA 1
#define ST_QIUTAO 2
#define ST_QIUTAOJIU 3

enum Color {
    SPADE = 1,
    HEART = 2,
    CLUB = 3,
    DIAMOND = 4
};

int cardCount; //指向移到排道堆顶的第几张牌了
Card card[160] = {
	{7, 1, 0, 0},
	{8, 1, 0, 0},
	{8, 1, 0, 0},
	{9, 1, 0, 0},
	{9, 1, 0, 0},
	{10, 1, 0, 0},
	{10, 1, 0, 0},

	{10, 2, 0, 0},
	{10, 2, 0, 0},
	{11, 2, 0, 0},

	{2, 3, 0, 0},
	{3, 3, 0, 0},
	{4, 3, 0, 0},
	{5, 3, 0, 0},
	{6, 3, 0, 0},
	{7, 3, 0, 0},
	{8, 3, 0, 0},
	{8, 3, 0, 0},
	{9, 3, 0, 0},
	{9, 3, 0, 0},
	{10, 3, 0, 0},
	{10, 3, 0, 0},
	{11, 3, 0, 0},
	{11, 3, 0, 0},

	{6, 4, 0, 0},
	{7, 4, 0, 0},
	{8, 4, 0, 0},
	{9, 4, 0, 0},
	{10, 4, 0, 0},
	{13, 4, 0, 0},
	
	{4, 2, 1, 0},
	{7, 2, 1, 0},
	{10, 2, 1, 0},

	{4, 4, 1, 0},
	{5, 4, 1, 0},

	{4, 1, 2, 0},
	{5, 1, 2, 0},
	{6, 1, 2, 0},
	{7, 1, 2, 0},
	{8, 1, 2, 0},

	{5, 3, 2, 0},
	{6, 3, 2, 0},
	{7, 3, 2, 0},
	{8, 3, 2, 0},

	{2, 2, 3, 0},
	{2, 2, 3, 0},
	{8, 2, 3, 0},
	{9, 2, 3, 0},
	{11, 2, 3, 0},
	{12, 2, 3, 0},
	{13, 2, 3, 0},
	
	{2, 4, 3, 0},
	{2, 4, 3, 0},
	{3, 4, 3, 0},
	{4, 4, 3, 0},
	{5, 4, 3, 0},
	{6, 4, 3, 0},
	{6, 4, 3, 0},
	{7, 4, 3, 0},
	{7, 4, 3, 0},
	{8, 4, 3, 0},
	{8, 4, 3, 0},
	{9, 4, 3, 0},
	{10, 4, 3, 0},
	{10, 4, 3, 0},
	{11, 4, 3, 0},
	
	{3, 2, 4, 0},
	{4, 2, 4, 0},
	{5, 2, 4, 0},
	{6, 2, 4, 0},
	{6, 2, 4, 0},
	{7, 2, 4, 0},
	{8, 2, 4, 0},
	{9, 2, 4, 0},
	{12, 2, 4, 0},

	{2, 4, 4, 0},
	{3, 4, 4, 0},
	{12, 4, 4, 0},

	{3, 1, 5, 0},
	{9, 1, 5, 0},

	{3, 3, 5, 0},
	{9, 3, 5, 0},

	{9, 4, 5, 0},

	{1, 1, 6, 1},
	{1, 3, 6, 1},
	{1, 4, 6, 1}
};
int Count;
int Heap[160];
int dropCount;
int dropHeap[160];

typedef struct
{
	char gender;
	int died;
	int life;//生命值 
	int hand[20];//手牌 
	int handnum;//手牌数量 
	int weapon;//全用int型是为了方便洗牌
	int shield;
	int horse_1;//+1马
	int horse_2;//-1马
	int allnum;//所有手牌的 
	int trial[10];
	int trialnum;
	int atkRange;//攻击距离
	int inchains; // chains
	int usejiu; // 0: no, 1:use, 2:used
	int shacount;
}Player;

Player all[5];//所有玩家
int PlayerCount, currentPlayer;

void calcDistance(int from, int to)
{
    
}

void shuffle(int *cards, int size)
{
    int i, n, t;
    for (i = 0; i < size; i++)
    {
        n = rand() % (i + 1);
        t = cards[i];
        cards[i] = cards[n];
        cards[n] = t;
    }
}

int relate(Card card, int j)
{
	if (card.name == sha)
	{
		if (all[0].atkRange < ((5 - j) < j ? (5 - j) : j) + all[j].horse_1)
		{
			return 0;
		}
	}

	if (card.name == shunshou)
	{
		if ((1 + all[0].horse_2) < (((5 - j) < j ? (5 - j) : j) + all[j].horse_1))
		{
			return 0;
		}
	}

	if (card.name == huogong)
	{
		if (all[j].handnum == 0)
		{
			return 0;
		}
	}

	else 
	{
		return 1;
	}
}
int wound(int target, int value, int type)
{
    int i;
    if (all[target].shield == baiyin)
        value = 1;
    if (all[target].shield == tengjia && type == 1)
        value += 1;
    all[target].life -= value;
    if (all[target].life <= 0)
    {
        for (i = 0; i < PlayerCount; ++i)
        {
            int pos = (currentPlayer + i) % PlayerCount, use;
            if (pos == target)
                use = playCard(pos, ST_QIUTAOJIU);
            else
                use = playCard(pos, ST_QIUTAO);
            if (use)
                --i;
            if (all[target].life > 0)
                break;
            else
            {
                die(target); // ?
            }
        }
    }
    if (all[target].inchains && type > 0)
    {
        all[target].inchains
        for (i = 0; i < PlayerCount; ++i)
        {
            int pos = (currentPlayer + i) % PlayerCount, use;
            if (all[pos].inchains)
                if (wound(pos, value, type))
        }
    }
    return 0;
}

int sha(int i)//还有雌雄双股剑和青釭剑没有输入 
{
	if(all[0].shacount > 0 && all[0].weapon != zhuge)
	{
		printf("你已经使用过杀了，不能再使用杀了。\n");
		return 0;
	}
	else
	{
		int j;
		do
		{
		    printf("请指定一个目标:");
    		scanf("%d", &j);
    		if (relate())
			{
				printf("打不着")；
				break；
			}
		} while(1);
		if(all[0].weapon == "zhuqueyushan")
		{
			printf("是否发动朱雀羽扇?");
			int k10;
			scanf("%d", k10);
			if(k10 == 1)
			{
				a[all[0].hand[i]].type = huosha;
			}
		}
		printf("你对computer%d打出了一张杀", j);
		Del(0, i);
		all[0].shacount++;//表示你不能再出杀了，除非诸葛 
		if(playCard(j, 1) == 0)
		{
			if(all[0].weapon == hanbingjian && all[j].allnum >= 1)
			{//这里应该是总的牌数 
				printf("是否发动寒冰剑？"); 
				int k11;
				scanf("%d", &k11);
				if(k11 == 0)
				{
					wound(j);
					//想办法结束这个函数 
				}
				else if(k11 == 1)
				{
					printf("请选择要弃掉的两张牌：");
					int k12, k13;
					scanf("%d%d", &k12, &k13);
					Del(j, k12);
					Del(j, k13); 
					printf("你弃掉了玩家%d的", j);//这就是说弃了玩家的那两张牌 
					f(a[all[j].hand[k12]]);
					f(a[all[j].hand[k13]]);//这里只能弃掉手牌，其他牌之后再改进 
				}
			}
			else if(all[0].weapon == "qilingong")
			{
				if(all[j].horse1 == 0 && all[j].horse2 == 0)
				{
					//想办法结束 
				}
				else
				{
					printf("是否发动麒麟弓?");
					int k8;
					scanf("%d", k8);
					if(k8 == 0)
					{
						//想办法结束 
					}
					else if(k8 == 1)
					{
						if(all[j].horse1 == 0 && all[j].horse2 != 0)
						{
							printf("你弃掉了computer%d的-1马", j);
							Del(j, horse2);
						}
						else if(all[j].horse2 == 0 && all[j].horse1 != 0)
						{
							printf("你弃掉了computer%d的+1马", j);
							Del(j, horse1);
						}
						else
						{
							printf("请选择一匹马：");
							int k9;
							scanf("%d", &k9);
							if(k9 == 1)
							{
								printf("你弃掉了computer%d的-1马", j);
								Del(j, horse2);
							}
							else if(k9 == 2)
							{
								printf("你弃掉了computer%d的+1马", j);
								Del(j, horse1);
							}
						}
					}
				}
			}
			wound(j, 1 + (all[0].usejiu == 1));
		}
		else if(computer(j, sha, ) == 1)
		{
			if(all[0].weapon == "zhangbashemao" && all[0].handnum >= 2)
			{
				printf("是否使用贯石斧？\n");
				int k;
				scanf("%d", &k);
				if(k == 0)
				{
					//想办法结束这个函数 
				}
				else
				{
					printf("请输入两张牌：");
					int k1, k2;
					scanf("%d%d", &k1, &k2);
					printf("你丢弃了");
					f(a[all[0].hand[k1]]);
					f(a[all[0].hand[k2]]);
					printf("贯石斧效果发动，强制扣血。\n");
					wound(j);
					Del(0, k1);
					Del(0, k2);
				}
			}
			else if(all[0].weapon == "qinglognyanyuedao")
			{
				while(computer(j, sha, ) == 1)
				{
					int k4, k5 = 0;
					for(k4 = 1, k4 < all[0].handnum, k4++)
					{
						if(a[all[0].hand[k4]].type == "sha")
						{
							k5 = 1;
						}
					}
					if(k5 = 1)
					{
						printf("是否发动青龙偃月刀:");
						int k6;
						scanf("%d", &k6);
						if(k6 == 0)
						{
							return -1;
						}
						else if(k6 == 1)
						{
							printf("请指定一张牌:");
							int k7;
							scanf("%d", k7);
							printf("你打出了");
							f(a[all[0].hand[k7]]);
							Del(0, k7);
							computer(j, sha, );
							if(computer(j, sha, ) == 0)
							{
								wound(j);
							}
						}
					}
				}
			}
			else if(all[0].weapon == "zhugeliannu")
			{
				all[0].state[1] = 1;
			}
		}
	}
}

void nanmanruqin(int i)
{
	int k1;
	for(k1 = 1; k1 < 5; k1++)
	{
		computer(k1, nanmanruqin);
		if(computer(k1, nanmanruqin) == 0)
		{
			wound(k1);
		}
	}
	Del(0, i);
	computer(k1, nanmanruqin);
	if(computer(k1, nanmanruqin) == 0) 
	{
		wound(k1);
	}
	else if(computer(k1, nanmanruqin) == 1)//无懈可击了
	{
		for(computer(k1, nanmanruqin) == 1)
		{
			computer(k1, nanmanruqin);//记住这一行 
			printf("是否使用无懈可击？");//待会改成没有无懈可击就不仅如此这个循环 
			int k2;
			scanf("%d", &k2);
			if(k2 == 0)
			{
				break;
			}
			else if(k2 == 1)
			{
				printf("请选择要出的牌:");
				int k3;
				scanf("%d", &k3);
				printf("你打出了一张无懈可击\n");
				Del(0, k3); 
			}
		}
	}
}

void wanjianqifa(int i)
{
	int k;
	for(k = 1; k < 5; k++)
	{
		computer(k1, wanjianqifa);
		if(computer(k1, wanjianqifa) == 0)
		{
			wound(k1);
		}
	}
	Del[0, i];
	if(computer(k1, wanjianqifa) == 0) 
	{
		wound(k1);
	}
	else if(computer(k1, wanjianqifa) == 1)//无懈可击了
	{
		for(computer(k1, wanjianqifa) == 1)
		{
			printf("是否使用无懈可击？");//待会改成没有无懈可击就不仅如此这个循环 
			int k2;
			scanf("%d", &k2);
			if(k2 == 0)
			{
				break;
			}
			else if(k2 == 1)
			{
				printf("请选择要出的牌:");
				int k3;
				scanf("%d", &k3);
				printf("你打出了一张无懈可击\n");
				Del(0, k3); 
			}
		}
	}
}

void bingliangcunduan(int i)
{
	printf("请指定一名玩家:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("该玩家距离太远。");
		scanf("%d", &j);
	}
	printf("你对玩家%d使用了一张兵粮寸断", j);
	all[j].trial[all[j].trialnum] = all[0].hand[i];
	all[j].trialnum++
}

void huogong(int i)
{
	printf("请指定一名玩家:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("该玩家没有手牌。");
		scanf("%d", &j);
	}
	printf("你对玩家%d使用了火攻", j);
	int k = computer(j, huogong);//k是一种花色 
	printf("请丢弃一张花色为k的是手牌。");
	int k1;
	scanf("%d", &k1);
	for(a[all[0].hand[k1]].type != k && a[all[0].hand[k1]].type != 0)
	{
		printf("这张牌不是同花色的牌。");
		scanf("%d", &k1); 
	}
	if(a[all[0].hand[k1]].type != k)
	{
		wound(j);
	}
}//在此之前的computer哪里都有问题 

void jiedaosharen(int i)
{
	printf("请指定一名玩家:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("该玩家没有手牌。");
		scanf("%d", &j);
	}
	printf("请指定另外一名被杀的玩家:");
	int j1;
	scanf("%d", &j1);
	while(relate(a[all[0].hand[i]].type, j1) = 0)
	{
		printf("该玩家没有手牌。");
		scanf("%d", &j1);
	}
	if(computer(j, jiedao) == 0)
	{
		shift(j, 0, weapon);
		printf("你抽取了玩家j的武器牌。"); 
	}
	Del(0, i);
}

void wugufengdeng(int i)
{
	Del(i);
	int j;
	for(j = 0; j < 5; j++)
	{
		movecard();
		f(b[heap]);
	}
	printf("请选择一张牌：")；
	int k;
	scanf("%d", &k);
	all[0].hand[all[0].handnum] = b[heap - k];
	all[0].handnum++;
	int k1;
	for(k1 != ) //巴拉巴拉，就是把牌分给各个电脑 
}

void wuzhongshengyou(int i)
{
	Del(i);
	getcard(0, 2);
}

void taoyuanjieyi(int i)
{
	Del(i);
	int j;
	for(j = 0 && all[j].life != 4 && all[j].life != 0)
	{
		tao[j];
	}
}

void shunshouqianyang(int i)
{
	printf("请指定一名玩家:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("你够不着。");
		scanf("%d", &j);
	}
	
	Del(0, i);
	if(computer(j, shunshouqianyang) == 0)
	{
		printf("请选择一张牌:");
		int k;
		scanf("%d", &k);
		Del(j, k);
		all[0].hand[all[0].handnum] = "zhezhangpai";
		all[0].handnum++;
	}
	else if(computer(j, shunshouqinayng) == 1)
	{
		//判定一下是不是有无懈可击
		//如果有
		printf("是否使用无懈可击:");
		int k1;
		scanf("%d", &k1);
		if(k1 == 1)
		{
			int k2;
			scanf("%d", &k2);
			while(all[0].hand[k2] != "wuxiekeji")
			{
				printf("这张牌不是无懈可击。\n");
				scanf("%d", &k2);
			}
			Del(0, k2);
			printf("你打出了一张无懈可击。\n"); 
		}
	}
}//这里暂时没有考虑无懈可击对轰，待会儿再说

void guohechaiqiao(int i)
{
	printf("请指定一名玩家:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("该玩家没有牌。");
		scanf("%d", &j);
	}
	Del(0, i);
	if(computer(j, guohechaoqiao) == 0)
	{
		printf("请选择一张牌:");
		int k;
		scanf("%d", &k);
		Del(j, k);
	}
	else//无懈可击对轰，待会儿单独写一个 
}
 
void juedou()
{
	printf("请指定一名玩家:");
	int j;
	scanf("%d", &j);
	printf("请出杀。\n");
	int k0;
	scanf("%d", &k0);
	while(zhezhangpaibushisha)//细化 
	{
		printf("这张牌不是杀。");
		scanf("%d", &k0);
	}
	Del(0, k0);
	if(computer(j, juedou) == 0)
	{
		wound(j);
	}
	else if(computer(j, juedou) != 0)
	{
		while(computer(j, juedou) != 0)
		{
			printf("请出杀。\n");
			while(zhezhangpaibushisha)//细化 
			{
				printf("这张牌不是杀。");
				scanf("%d", &k0);
			}
			Del(0, k0);
		}
	}
	//无懈可击对轰 
}

void shandian(int i)
{
	printf("请指定一名玩家:");
	int j;
	scanf("%d", &j);
	Del(0, j);
	all[j].trial[all[j].trialnum] = "shandian";
	all[j].trialnum++;
}

int zhuangbei(int i)//四个部分几乎一样，可以考虑优化 
{
	printf("是否装备这张牌?");
	Del(0,i);
	if(a[all[0].hand[i]].type == weapon)
	{
		if (all[0].weapon == 0)
		{
			all[0].weapon == all[0].hand [i];
		}
		else
		{
			printf("是否换掉现有武器。\n");
			int k;
			scanf("%d", &k);
			if(k == 1)
			{
				Del(0, weapon);
				all[0].weapon == all[0].hand [i];
			}
		}
	}
	else if(a[all[0].hand[i]].type == "shield")
	{
		if (all[0].shield == 0)
		{
			all[0].shield == all[0].hand[i];
		}
		else
		{
			printf("是否换掉现有防具。\n");
			int k;
			scanf("%d", &k);
			if(k == 1)
			{
				Del(0, shield);
				all[0].shield == all[0].hand [i];
			}
		}
	}
	else if(a[all[0].hand[i]].type == horse1)
	{
		if (all[0].horse1 == 0)
		{
			all[0].horse1 == all[0].hand[i];
		}
		else
		{
			printf("是否换掉现有-1马。\n");
			int k;
			scanf("%d", &k);
			if(k == 1)
			{
				Del(0, horse1);
				all[0].horse1 == all[0].hand[i];
			}
		}
	}
	else if(a[all[0].hand[i]].type == horse2)
	{
		if (all[0].horse2 == 0)
		{
			all[0].horse2 == all[0].hand [i];
		}
		else
		{
			printf("是否换掉现有+1马。\n");
			int k;
			scanf("%d", &k);
			if(k == 1)
			{
				Del(0, horse2);
				all[0].horse2 == all[0].hand[i];
			}
		}
	}
}

void tao(int i, j)
{
	if(all[j].life < 4)
	{
		all[j].life++;
	}
	Del(0, i);
}

//下面是不是自己回合的应对之法

int fsha()
{
	if(all[0].shield == "baguazhen")
	{
		trial(baguazhen);
		if(trial == 1)
		{
			return 1;
		}
		else
		{
			printf("判定失败，请出一张闪。");
			int k;
			printf("%d", k);
			while(a[all[0].hand[k]].type != "shan" && all[0].hand[k]].type != 0)
			{
				printf("这张牌不是闪，请重新出一张牌。\n");
				scanf("%d", &k);
			}
			if(all[0].hand[k]].type != "shan")
			{
				printf("你打出了一张闪。\n");
				Del(0, k);
				return 1;
			}
			else if(all[0].hand[k]].type != 0)
			{
				return 0;
			}
		}
	}
	else if(all[0].shield != 0)
	{
		printf("请出一张闪。\n");
		int k;
		printf("%d", &k);
		while(a[all[0].hand[k]].type != "shan" && all[0].hand[k]].type != 0)
		{
			printf("这张牌不是闪，请重新出一张牌。\n");
				scanf("%d", &k);
		}
		if(all[0].hand[k]].type != "shan")
		{
			printf("你打出了一张闪。\n");
			Del(0, k);
			return 1;
		}
		else if(all[0].hand[k]].type != 0)
		{
			return 0;
		}	 
	}
}

int fnanman()
{
	if(all[0].shield == "tengjia")
	{
		return 1;
	}
	else if
	{
		printf("请出一张杀。\n");
		int k1;
		scanf("%d", &k1);
		while(all[0].hand[k1] != "sha" && all[0].hand[k1] != 0)
		{
			printf("这张牌不是杀.\n");
			scanf("%d", &k1);
		}
		if(all[0].hand[k1] != "sha")
		{
			Del(0, k1)
			return 1;
		}
		else if(all[0].hand[k1] != 0)
		{
			return 0;
		}
	}
}

int fwanjian()
{
	if(all[0].shield == "tengjia")
	{
		return 1;
	}
	else if(all[0].shield == 0)
	{
		printf("请出一张闪。\n");
		int k1;
		scanf("%d", &k1);
		while(all[0].hand[k1] != "shan" && all[0].hand[k1] != 0)
		{
			printf("这张牌不是闪.\n");
			scanf("%d", &k1);
		}
		if(all[0].hand[k1] != "shan")
		{
			Del(0, k1)
			return 1;
		}
		else if(all[0].hand[k1] != 0)
		{
			return 0;
		}
	}
	else if(all[0].shield == "baguazhen")
	{
		trial(baguazhen);
		if(trial == 1)
		{
			return 1;
		}
		else
		{
			printf("判定失败，请出一张闪。");
			int k;
			printf("%d", &k);
			while(a[all[0].hand[k]].type != "shan" && all[0].hand[k]].type != 0)
			{
				printf("这张牌不是闪，请重新出一张牌。\n");
				scanf("%d", &k);
			}
			if(all[0].hand[k]].type != "shan")
			{
				printf("你打出了一张闪。\n");
				Del(0, k);
				return 1;
			}
			else if(all[0].hand[k]].type != 0)
			{
				return 0;
			}
		}
	}
}

int fwuxiekeji()
{
	//无懈可击对轰 
}

int fhuogong()
{
	printf("请出示一张牌。\n");
	int k;
	scanf("%d", &k);
	return color;//返回值是颜色 
}

int fjiedaosharen()
{
	printf("请出一张杀。\n");
	int k;
	scanf("%d", &k);
	if(all[0].hand[k] != "sha" && all[0].hand[k] != 0)
	{
		printf("这张牌不是杀。\n");
		scanf("%d", &k);
	}
	if(all[0].hand[k] != "sha")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int juedou()
{
	printf("请出一张杀.\n");
	int k;
	scanf("%d", &k);
	if(all[0].hand[k] != "sha" && all[0].hand[k] != 0)
	{
		printf("这张牌不是杀。\n");
		scanf("%d", &k);
	}
	if(all[0].hand[k] != "sha")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int guohechaiqiao()
{
	//无懈可击对轰[]
}

int shunshouqianyang()
{
	//无懈可击对轰 
}

int playCard(int id, int state)
{
    if (id == 0)
    {
        if (state == 0)
        {
            while (1)
            {
                int t = -2;
                while (t < 0 || t >= all[id].handnum)
                {
                    printf("选择");
                    scanf("%d", &t);
                    if (t == -1)
                    {
                        return -1;
                    }
                }
                switch (card[all[id].hand[t]].name)
                {
                case sha:
                case huosha:
                case leisha:
                    if (sha(t))
                        return t;
                    else
                        break;
                case shan:
                    break;
                case tao:
                    if (tao(t))
                        return t;
                    else
                        break;
                }
            }
        }
    }
    else
    {
        // put ai here
    }
}

int playRound(int player)
{
    getcard(player, 2);
    while (playCard(player, 0) >= 0)
    {
        
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 160; ++i)
        Heap[i] = i;
    Count = 160;
    shuffle(Heap, 160);
}
}
