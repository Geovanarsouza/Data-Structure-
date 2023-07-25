typedef struct ponto Ponto;

Ponto* criarPonto(float x, float y);

void liberarMemoria(Ponto *ponto);

void atribuirNovosValores(Ponto *ponto, float x, float y);

float calcularDistancia(Ponto *ponto1, Ponto *ponto2);
