# Write a Shell in C


[Ref] <https://brennan.io/2015/01/16/write-a-shell-in-c/>

## Basic lifetime of a shell

top down 방식으로 shell 소스를 분석해본다.
쉘(shell)은 크게 세 가지의 프로세스로 동작한다.

* Initialize : 쉘은 설정 파일을 읽고(read), 실행한다.(execute)
* Interpret : stdin으로부터 명령어(interactive or file)를 읽고 실행한다.
* Terminate : 명령어를 수행 후, 쉘은 종료 명령을 실행하고 메모리를 비운 다음 종료한다.

쉘은 대부분의 프로그램에 적용되어있지만 
비교적 간단한 쉘이다. bash 쉘처럼 설정파일이 있는 것이 아닌 단순히 loop 상에 함수를 수행 후, 종료시킬 것이다.

단순히 looping 프로그램이 아닌 아키텍처 관점에서, 쉘의 lifecycle을 이해하는 것이 중요하다.

```c
int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}
```

## Basic loop of a shell

* Read : stdout으로 부터 명령을 읽음
* Parse : 명령어를 프로그램과 인자로 나눈다.
* Execute : Parse 처리된 명령을 실행한다.

```c
void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> "); // 프롬프트 출력
    line = lsh_read_line(); // Read
    args = lsh_split_line(line); // Parse
    status = lsh_execute(args); // Execute

    free(line);
    free(args);
  } while (status);
}
```

## Reading a line

stdin으로부터 한 줄을 읽는게 간단한 것처럼 들리지만, C에서는 번거롭다. 쉘 입장에서 유저가 입력할 text의 양을 모르기 때문이다. buffer 사이즈를 단순히 임의의 값으로 할당하는 것이 아닌 동적으로 재할당을 해주어야 한다.

```c
#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void)
{
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Read a character
    c = getchar();

    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
```

loop 안에서 문자를 읽을 때, char 타입이 아닌 int 타입에 저장한다.
**EOF는 문자가 아닌 정수 값(-1)이다.**

getline 함수를 이용하면 간단히 메모리 동적할당과 EOF처리가 가능하다.
<pre>
char *lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}
</pre>


## Parsing the line
공백(space, whitespace)으로만 구분한다.

```c
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char \*\*lsh_split_line(char \*line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char \*\*tokens = malloc(bufsize * sizeof(char*));
  char \*token;
  
  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  
  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;
    
    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    
    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}
```

## How shells start processes

## Putting together builtins and processes
