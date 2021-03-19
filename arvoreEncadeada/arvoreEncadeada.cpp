template<typename tipo>
class noArvore{
    public:
        tipo dado;
        noArvore* prox; //irmão
        noArvore* filho; //filho
};

template<typename tipo>
class arvore{
    public:
        noArvore* raiz;
};