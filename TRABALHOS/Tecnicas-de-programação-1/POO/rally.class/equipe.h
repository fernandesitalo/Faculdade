class equipe
{
    private:
        int INSCR;
        float tempo[3];

    public:
        void setINSCR(int INSCR);
        int getINSCR();


        void setT1(int t);
        int getT1();


        void setT2(int t);
        int getT2();


        void setT3(int t);
        int getT3();


        float getPET(int tempoPadrao, int etapa);
};
