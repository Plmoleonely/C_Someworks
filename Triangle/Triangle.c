//U10810026 �a�ͤT ������
//double���A��scanf�n�]%lf���M�|�X���A���ثevs���ۦ�]�w�ҥH���ΡA���O�I�_�����٬O�[�W�h�C

#include <stdio.h>
#include <math.h>
#include <string.h>

#define Stringlength 80

void main()
{
    double a, b, c;
    double s, area;
    char ask[Stringlength] = "�п�J�T���ΤT���";
    char ansyes[Stringlength] = "�o�ӤT���Ϊ����n��:";
    //�U���o�C�쥻�n�g�i�H���s��J�A���]���̫�@�檺else�|���ͤpbug�ҥH���Ȯɤ��ĥΡC
    char reset[Stringlength] = "��������J<=0���ȼ�~�Э��s��J!!";
    printf("%s\n" ,ask);
    scanf("%lf%lf%lf", &a, &b, &c);
    
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));

    if(a + b > c && a + c > b && b + c > a){
        printf("%s %f\n", ansyes, area);
    }
    else{
        printf("%d\n", 0);
    }
}