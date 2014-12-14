void render(const byte* frame, int screen) {
  for (int i = 0; i < 8; i++) {
    lc.setColumn(screen, i, frame[7-i]);
  }
}
