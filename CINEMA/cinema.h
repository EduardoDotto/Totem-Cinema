struct ingresso
{
    char nome[50];
    int poltrona;
    float preco;
    int ocupado;
};
//DECLARANDO FUNÇÕES
void menu(struct ingresso vendas[], int tamanho);
void preparavenda(struct ingresso vendas[], int tamanho);
void mostrapoltronas(struct ingresso vendas[], int tamanho);
void video ();
void relatorio (struct ingresso vendas[], int tamanho);
