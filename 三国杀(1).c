#include <stdio.h>
#include <stdlib.h>

 typedef struct//�����˵������и�ɻ�ֻ�ܶ��Լ��ã����G��һ��װ���ͳ�Ϊһ��״̬�����跢�� 
{//������ʱ������ƣ���и�ɻ�ֻ�ܹ����ж�ǰʹ�ã������ܹ��ڸ�����ȥ��ʱ���� 
//�ټ�Ҳд��״̬���棬�����÷��� 
	int num;
	int color;
	int name;//�ö�ط�û�з���ֵ,�ö�ط�ȱ����ɾ������
	int type;//�����ƣ�װ����ɶ��
}Card;//��ɱ�������

#define sha 0// ɱ 
#define huosha 1//��ɱ 
#define leisha 2//��ɱ 
#define shan 3//�� 
#define tao 4//�� 
#define jiu 5//�� 
#define juedou 6//���� 
#define wuzhong 7//�������� 
#define guohe 8//���Ӳ��� 
#define shunshou 9//˳��ǣ�� 
#define jiedao 10//�赶ɱ�� 
#define nanman 11//�������� 
#define wanjian 12//����뷢 
#define taoyuan 13//��԰���� 
#define wugu 14//��ȷ�� 
#define wuxie 15//��и�ɻ� 
#define huogong 16//�� 
#define tiesuo 17//�������� 
#define lebu 18//�ֲ�˼�� 
#define shandian 19//���� 
#define bingliang 20//������� 
#define cixiong 21//����˫�ɽ� 
#define qinglong 22//�������µ� 
#define qinggang 23//���G�� 
#define zhangba 24//�ɰ���ì 
#define qilin 25//���빭 
#define zhuge 26//������� 
#define guanshi 27//��ʯ�� 
#define fangtian 28//���컭� 
#define hanbing 29//������ 
#define guding 30//�Ŷ��� 
#define zhuque 31//��ȸ���� 
#define bagua 32//������ 
#define renwang 33//������ 
#define tengjia 34//�ټ� 
#define baiyin 35//����ʨ�� 
#define horse1 36//+1�� 
#define horse2 37//-1��

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

int cardCount; //ָ���Ƶ��ŵ��Ѷ��ĵڼ�������
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
	int life;//����ֵ 
	int hand[20];//���� 
	int handnum;//�������� 
	int weapon;//ȫ��int����Ϊ�˷���ϴ��
	int shield;
	int horse_1;//+1��
	int horse_2;//-1��
	int allnum;//�������Ƶ� 
	int trial[10];
	int trialnum;
	int atkRange;//��������
	int inchains; // chains
	int usejiu; // 0: no, 1:use, 2:used
	int shacount;
}Player;

Player all[5];//�������
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

int sha(int i)//���д���˫�ɽ������G��û������ 
{
	if(all[0].shacount > 0 && all[0].weapon != zhuge)
	{
		printf("���Ѿ�ʹ�ù�ɱ�ˣ�������ʹ��ɱ�ˡ�\n");
		return 0;
	}
	else
	{
		int j;
		do
		{
		    printf("��ָ��һ��Ŀ��:");
    		scanf("%d", &j);
    		if (relate())
			{
				printf("����")��
				break��
			}
		} while(1);
		if(all[0].weapon == "zhuqueyushan")
		{
			printf("�Ƿ񷢶���ȸ����?");
			int k10;
			scanf("%d", k10);
			if(k10 == 1)
			{
				a[all[0].hand[i]].type = huosha;
			}
		}
		printf("���computer%d�����һ��ɱ", j);
		Del(0, i);
		all[0].shacount++;//��ʾ�㲻���ٳ�ɱ�ˣ�������� 
		if(playCard(j, 1) == 0)
		{
			if(all[0].weapon == hanbingjian && all[j].allnum >= 1)
			{//����Ӧ�����ܵ����� 
				printf("�Ƿ񷢶���������"); 
				int k11;
				scanf("%d", &k11);
				if(k11 == 0)
				{
					wound(j);
					//��취����������� 
				}
				else if(k11 == 1)
				{
					printf("��ѡ��Ҫ�����������ƣ�");
					int k12, k13;
					scanf("%d%d", &k12, &k13);
					Del(j, k12);
					Del(j, k13); 
					printf("�����������%d��", j);//�����˵������ҵ��������� 
					f(a[all[j].hand[k12]]);
					f(a[all[j].hand[k13]]);//����ֻ���������ƣ�������֮���ٸĽ� 
				}
			}
			else if(all[0].weapon == "qilingong")
			{
				if(all[j].horse1 == 0 && all[j].horse2 == 0)
				{
					//��취���� 
				}
				else
				{
					printf("�Ƿ񷢶����빭?");
					int k8;
					scanf("%d", k8);
					if(k8 == 0)
					{
						//��취���� 
					}
					else if(k8 == 1)
					{
						if(all[j].horse1 == 0 && all[j].horse2 != 0)
						{
							printf("��������computer%d��-1��", j);
							Del(j, horse2);
						}
						else if(all[j].horse2 == 0 && all[j].horse1 != 0)
						{
							printf("��������computer%d��+1��", j);
							Del(j, horse1);
						}
						else
						{
							printf("��ѡ��һƥ��");
							int k9;
							scanf("%d", &k9);
							if(k9 == 1)
							{
								printf("��������computer%d��-1��", j);
								Del(j, horse2);
							}
							else if(k9 == 2)
							{
								printf("��������computer%d��+1��", j);
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
				printf("�Ƿ�ʹ�ù�ʯ����\n");
				int k;
				scanf("%d", &k);
				if(k == 0)
				{
					//��취����������� 
				}
				else
				{
					printf("�����������ƣ�");
					int k1, k2;
					scanf("%d%d", &k1, &k2);
					printf("�㶪����");
					f(a[all[0].hand[k1]]);
					f(a[all[0].hand[k2]]);
					printf("��ʯ��Ч��������ǿ�ƿ�Ѫ��\n");
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
						printf("�Ƿ񷢶��������µ�:");
						int k6;
						scanf("%d", &k6);
						if(k6 == 0)
						{
							return -1;
						}
						else if(k6 == 1)
						{
							printf("��ָ��һ����:");
							int k7;
							scanf("%d", k7);
							printf("������");
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
	else if(computer(k1, nanmanruqin) == 1)//��и�ɻ���
	{
		for(computer(k1, nanmanruqin) == 1)
		{
			computer(k1, nanmanruqin);//��ס��һ�� 
			printf("�Ƿ�ʹ����и�ɻ���");//����ĳ�û����и�ɻ��Ͳ���������ѭ�� 
			int k2;
			scanf("%d", &k2);
			if(k2 == 0)
			{
				break;
			}
			else if(k2 == 1)
			{
				printf("��ѡ��Ҫ������:");
				int k3;
				scanf("%d", &k3);
				printf("������һ����и�ɻ�\n");
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
	else if(computer(k1, wanjianqifa) == 1)//��и�ɻ���
	{
		for(computer(k1, wanjianqifa) == 1)
		{
			printf("�Ƿ�ʹ����и�ɻ���");//����ĳ�û����и�ɻ��Ͳ���������ѭ�� 
			int k2;
			scanf("%d", &k2);
			if(k2 == 0)
			{
				break;
			}
			else if(k2 == 1)
			{
				printf("��ѡ��Ҫ������:");
				int k3;
				scanf("%d", &k3);
				printf("������һ����и�ɻ�\n");
				Del(0, k3); 
			}
		}
	}
}

void bingliangcunduan(int i)
{
	printf("��ָ��һ�����:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("����Ҿ���̫Զ��");
		scanf("%d", &j);
	}
	printf("������%dʹ����һ�ű������", j);
	all[j].trial[all[j].trialnum] = all[0].hand[i];
	all[j].trialnum++
}

void huogong(int i)
{
	printf("��ָ��һ�����:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("�����û�����ơ�");
		scanf("%d", &j);
	}
	printf("������%dʹ���˻�", j);
	int k = computer(j, huogong);//k��һ�ֻ�ɫ 
	printf("�붪��һ�Ż�ɫΪk�������ơ�");
	int k1;
	scanf("%d", &k1);
	for(a[all[0].hand[k1]].type != k && a[all[0].hand[k1]].type != 0)
	{
		printf("�����Ʋ���ͬ��ɫ���ơ�");
		scanf("%d", &k1); 
	}
	if(a[all[0].hand[k1]].type != k)
	{
		wound(j);
	}
}//�ڴ�֮ǰ��computer���ﶼ������ 

void jiedaosharen(int i)
{
	printf("��ָ��һ�����:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("�����û�����ơ�");
		scanf("%d", &j);
	}
	printf("��ָ������һ����ɱ�����:");
	int j1;
	scanf("%d", &j1);
	while(relate(a[all[0].hand[i]].type, j1) = 0)
	{
		printf("�����û�����ơ�");
		scanf("%d", &j1);
	}
	if(computer(j, jiedao) == 0)
	{
		shift(j, 0, weapon);
		printf("���ȡ�����j�������ơ�"); 
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
	printf("��ѡ��һ���ƣ�")��
	int k;
	scanf("%d", &k);
	all[0].hand[all[0].handnum] = b[heap - k];
	all[0].handnum++;
	int k1;
	for(k1 != ) //�������������ǰ��Ʒָ��������� 
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
	printf("��ָ��һ�����:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("�㹻���š�");
		scanf("%d", &j);
	}
	
	Del(0, i);
	if(computer(j, shunshouqianyang) == 0)
	{
		printf("��ѡ��һ����:");
		int k;
		scanf("%d", &k);
		Del(j, k);
		all[0].hand[all[0].handnum] = "zhezhangpai";
		all[0].handnum++;
	}
	else if(computer(j, shunshouqinayng) == 1)
	{
		//�ж�һ���ǲ�������и�ɻ�
		//�����
		printf("�Ƿ�ʹ����и�ɻ�:");
		int k1;
		scanf("%d", &k1);
		if(k1 == 1)
		{
			int k2;
			scanf("%d", &k2);
			while(all[0].hand[k2] != "wuxiekeji")
			{
				printf("�����Ʋ�����и�ɻ���\n");
				scanf("%d", &k2);
			}
			Del(0, k2);
			printf("������һ����и�ɻ���\n"); 
		}
	}
}//������ʱû�п�����и�ɻ��Ժ䣬�������˵

void guohechaiqiao(int i)
{
	printf("��ָ��һ�����:");
	int j;
	scanf("%d", &j);
	while(relate(a[all[0].hand[i]].type, j) = 0)
	{
		printf("�����û���ơ�");
		scanf("%d", &j);
	}
	Del(0, i);
	if(computer(j, guohechaoqiao) == 0)
	{
		printf("��ѡ��һ����:");
		int k;
		scanf("%d", &k);
		Del(j, k);
	}
	else//��и�ɻ��Ժ䣬���������дһ�� 
}
 
void juedou()
{
	printf("��ָ��һ�����:");
	int j;
	scanf("%d", &j);
	printf("���ɱ��\n");
	int k0;
	scanf("%d", &k0);
	while(zhezhangpaibushisha)//ϸ�� 
	{
		printf("�����Ʋ���ɱ��");
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
			printf("���ɱ��\n");
			while(zhezhangpaibushisha)//ϸ�� 
			{
				printf("�����Ʋ���ɱ��");
				scanf("%d", &k0);
			}
			Del(0, k0);
		}
	}
	//��и�ɻ��Ժ� 
}

void shandian(int i)
{
	printf("��ָ��һ�����:");
	int j;
	scanf("%d", &j);
	Del(0, j);
	all[j].trial[all[j].trialnum] = "shandian";
	all[j].trialnum++;
}

int zhuangbei(int i)//�ĸ����ּ���һ�������Կ����Ż� 
{
	printf("�Ƿ�װ��������?");
	Del(0,i);
	if(a[all[0].hand[i]].type == weapon)
	{
		if (all[0].weapon == 0)
		{
			all[0].weapon == all[0].hand [i];
		}
		else
		{
			printf("�Ƿ񻻵�����������\n");
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
			printf("�Ƿ񻻵����з��ߡ�\n");
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
			printf("�Ƿ񻻵�����-1��\n");
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
			printf("�Ƿ񻻵�����+1��\n");
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

//�����ǲ����Լ��غϵ�Ӧ��֮��

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
			printf("�ж�ʧ�ܣ����һ������");
			int k;
			printf("%d", k);
			while(a[all[0].hand[k]].type != "shan" && all[0].hand[k]].type != 0)
			{
				printf("�����Ʋ������������³�һ���ơ�\n");
				scanf("%d", &k);
			}
			if(all[0].hand[k]].type != "shan")
			{
				printf("������һ������\n");
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
		printf("���һ������\n");
		int k;
		printf("%d", &k);
		while(a[all[0].hand[k]].type != "shan" && all[0].hand[k]].type != 0)
		{
			printf("�����Ʋ������������³�һ���ơ�\n");
				scanf("%d", &k);
		}
		if(all[0].hand[k]].type != "shan")
		{
			printf("������һ������\n");
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
		printf("���һ��ɱ��\n");
		int k1;
		scanf("%d", &k1);
		while(all[0].hand[k1] != "sha" && all[0].hand[k1] != 0)
		{
			printf("�����Ʋ���ɱ.\n");
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
		printf("���һ������\n");
		int k1;
		scanf("%d", &k1);
		while(all[0].hand[k1] != "shan" && all[0].hand[k1] != 0)
		{
			printf("�����Ʋ�����.\n");
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
			printf("�ж�ʧ�ܣ����һ������");
			int k;
			printf("%d", &k);
			while(a[all[0].hand[k]].type != "shan" && all[0].hand[k]].type != 0)
			{
				printf("�����Ʋ������������³�һ���ơ�\n");
				scanf("%d", &k);
			}
			if(all[0].hand[k]].type != "shan")
			{
				printf("������һ������\n");
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
	//��и�ɻ��Ժ� 
}

int fhuogong()
{
	printf("���ʾһ���ơ�\n");
	int k;
	scanf("%d", &k);
	return color;//����ֵ����ɫ 
}

int fjiedaosharen()
{
	printf("���һ��ɱ��\n");
	int k;
	scanf("%d", &k);
	if(all[0].hand[k] != "sha" && all[0].hand[k] != 0)
	{
		printf("�����Ʋ���ɱ��\n");
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
	printf("���һ��ɱ.\n");
	int k;
	scanf("%d", &k);
	if(all[0].hand[k] != "sha" && all[0].hand[k] != 0)
	{
		printf("�����Ʋ���ɱ��\n");
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
	//��и�ɻ��Ժ�[]
}

int shunshouqianyang()
{
	//��и�ɻ��Ժ� 
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
                    printf("ѡ��");
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
