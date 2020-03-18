### 天皇的密码
日本天皇孙笑川坏事做尽，今天我们来把他号盗了。
拖入IDA，看见

```C
int __cdecl main(int argc, const char **argv, const char **envp)
{
  char Str1[8]; // [rsp+20h] [rbp-20h]
  __int64 v5; // [rsp+28h] [rbp-18h]
  int v6; // [rsp+30h] [rbp-10h]
  int v7; // [rsp+3Ch] [rbp-4h]

  _main();
  puts("     Welcome To JNCTF  ");
  puts("--------------------------");
  puts("----------Log In----------");
  puts("Username:Sun Xiaochuan");
  printf("Password:");
  *(_QWORD *)Str1 = 0i64;
  v5 = 0i64;
  v6 = 0;
  Str1[0] = 48;
  scanf("%s", Str1);
  upencode(Str1);
  downencode(&Str1[6]);
  printf("%s", Str1);
  v7 = 1;
  v7 = strcmp(Str1, "lupdkjgqemmb");
  if ( strlen(Str1) != 12 || v7 )
  {
    puts("\nWrong Password,try IDA or OD?");
  }
  else
  {
    puts("\nLog in successfully!");
    generate();
  }
  system("pause");
  return 0;
}
```

#### Solution 1:

把密码逆出来

可以看到输入的Str1被upencode和downencode两个函数处理了，进入函数

upencode:

```C
size_t __fastcall upencode(char *a1)
{
  size_t result; // rax
  int i; // [rsp+2Ch] [rbp-54h]
  char *Str; // [rsp+50h] [rbp-30h]

  Str = a1;
  for ( i = 0; ; ++i )
  {
    result = strlen(Str) >> 1;
    if ( i >= result )
      break;
    Str[i] = (Str[i] + 3) % 26 + 97;
  }
  return result;
}
```

strlen(Str)>>1即除以2

这里对Str的前半部分进行了类似凯撒密码的加密，但因为是直接用ASCII码处理，所以其实解不唯一，不过操作字母的话会方便直观一点。写脚本

```C
void updecode(char *a1)
{
  size_t result; // rax
  int i; // [rsp+2Ch] [rbp-54h]
  //char *Str; // [rsp+50h] [rbp-30h]

  //Str = a1;                        Str即a1，直接改掉 
  for ( i = 0; ; ++i )
  {
    result = strlen(a1) >> 1;
    if ( i >= result )
      break;
    a1[i] = ((a1[i] - 97)>=(97%26))?(a1[i] - 97-97%26+'a'):(a1[i] - 97+'h');
    a1[i]-=3;
    if(a1[i]-'a'<0) a1[i]+=26 ;
    else if(a1[i]-'z'>0) a1[i]-=26;
  }
}
```

downencode:

```C
__int64 __fastcall downencode(__int64 a1)
{
  int v1; // ecx
  __int64 result; // rax
  signed int i; // [rsp+Ch] [rbp-4h]
  __int64 v4; // [rsp+20h] [rbp+10h]

  v4 = a1;
  for ( i = 0; i <= 5; ++i )
  {
    v1 = (*(char *)(i + v4) + 5) % 26;
    result = (unsigned int)(v1 + 97);
    *(_BYTE *)(i + v4) = v1 + 97;
  }
  return result;
}
```

同理

```C
void downdecode(char *a1)
{
  int v1; // ecx
  //__int64 result; // rax
  signed int i; // [rsp+Ch] [rbp-4h]
  //__int64 v4; // [rsp+20h] [rbp+10h]           v4即a1，直接改掉 

  //v4 = a1;
  for ( i = 0; i <= 5; ++i )
  {
  	a1[i] = ((a1[i] - 97)>=(97%26))?(a1[i] - 97-97%26+'a'):(a1[i] - 97+'h');
    a1[i]-=5;
    if(a1[i]-'a'<0) a1[i]+=26 ;
    else if(a1[i]-'z'>0) a1[i]-=26;
    //result = (unsigned int)(v1 + 97);
    
  }
}
```

最后解码密文

```C
int main()
{
	char Str1[]="lupdkjgqemmb";
	updecode(Str1);
	downdecode(Str1+6);
	printf(Str1);
	return 0;
	
}
```



#### Solution 2:

截取生成flag的片段运行

```C
void generate()
{
  size_t v0; // rbx
  __int64 v2; // [rsp+20h] [rbp-60h]
  __int64 v3; // [rsp+28h] [rbp-58h]
  int v4; // [rsp+30h] [rbp-50h]
  char Str[8]; // [rsp+40h] [rbp-40h]
  int i; // [rsp+58h] [rbp-28h]
  char v7; // [rsp+5Fh] [rbp-21h]

  strcpy(Str, "2^bl`6id`e2`h");
  char v[]="flag{?????????????}";
  for ( i = 0; ; ++i )
  {
    v0 = i;
    if ( v0 >= strlen(Str) )
      break;
    if ( i & 1 )
      v7 = 1;
    else
      v7 = -1;
    *(v + i + 5) = Str[i] + v7;
  }
    printf("\nHere is the flag:  %s\n\n", v);
}
```



flag{1_am_7he_f1ag}
password: pythonisgood