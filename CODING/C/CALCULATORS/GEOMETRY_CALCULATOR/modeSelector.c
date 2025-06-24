//mode selector
int modeSelector(void){
  int mode = 0;
  while (printf("mode: "), scanf("%d", &mode) != 1){
    while (getchar() != '\n');
  }
  return mode;
}
