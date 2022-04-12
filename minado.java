import java.util.*;
import java.security.SecureRandom;



class Minado {
    private int size;
    private int bomb;

    Minado(int size, int bomb) {
        this.size = size;
        this.bomb = bomb;
    }

    public void minadoSetBomb(Minado minado, int x){
        minado.bomb = x;
    }

    public int minadoGetBomb(Minado minado){
        return minado.bomb;
    }

   public void minadoSetSize(Minado minado, int x){
        minado.size = x;
    }

   public int minadoGetSize(Minado minado){
        return minado.size;
    }

   void endGameL(Minado minado, Map map){ //-1 print final

   }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Digite a dimensao do campo :");
        int size = input.nextInt();
        int bomb = 0;
        while(bomb <= 0) {
            System.out.printf("Digite a quantidade de bombas (maximo : %d) :", (size * size) - 1);
            bomb = input.nextInt();
        }
        Minado minado = new Minado(size, bomb);
        Map [][]map;
        map = new Map[size][size];

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                map[i][j] = new Map();
                if(minado.bomb > 0) map[i][j].getBomb(map[i][j], minado);
            }
        }

        for(int i = 1; i < size - 1; i++){ // Ajeitar
            for(int j = 1; j < size - 1; j++){
                map[i][j].BombsNext(map, size, i, j);
            }
        }

        System.out.printf("%d", map[2][3].nextBomb);

        /*
        declara os objetos
         */


    }
}


class Map{
    public Integer nextBomb;
    public boolean isBomb;
    public boolean flagged;
    public boolean visible;
    SecureRandom random = new SecureRandom();
    Scanner input = new Scanner(System.in);


    Map(){
        this.flagged = false;
        this.isBomb = false;
        this.visible = false;
        this.nextBomb = 0;
    }

    void mapInit(Map map){
        this.flagged = false;
        this.isBomb = false;
        this.visible = false;
        this.nextBomb = 0;
    }

    void getBomb(Map map, Minado minado){
        if(minado.minadoGetBomb(minado) > 0){
            if(random.nextBoolean() == true){
                map.isBomb = true;
                minado.minadoSetBomb(minado, minado.minadoGetBomb(minado) - 1);
            }
        }
    }

    void getInput(Map map[][], Minado minado){
        int x, y = 0;
        System.out.printf("Selecione as coordenadas do bloco o qual deseja interagir (X, Y) :\n" +
                "O bloco deve estar dentro do mapa e ainda não pode ter sido revelado.");
        x = input.nextInt();
        System.out.println();
        y = input.nextInt();
        while((x <= 0 || x > minado.minadoGetSize(minado)) || (y <= 0 || y > minado.minadoGetSize(minado)) || map[x][y].visible == true){
            System.out.printf("Selecione as coordenadas do bloco o qual deseja interagir (X, Y) :\n" +
                    "O bloco deve estar dentro do mapa e ainda não pode ter sido revelado.");
            x = input.nextInt();
            System.out.println();
            y = input.nextInt();
        }
        System.out.printf("Digite 1 para descobrir o bloco\nDigite 2 para colocar uma bandeira no bloco");
        int action = input.nextInt();
        if (action == 1) Uncover(map[x][y], minado);
        if (action == 2) Flag(map[x][y], minado);
    }

    void Flag(Map map, Minado minado){
        map.flagged = true;
        minado.minadoSetBomb(minado, minado.minadoGetBomb(minado) - 1);
    }

    void Uncover(Map map, Minado minado){
        map.visible = true;
        if (map.isBomb == true) minado.endGameL(minado, map);
        map.Show(map);
    }

    void BombsNext(Map map[][], int size, int i, int j){
        if (map[i + 1][j].isBomb == true) map[i][j].nextBomb++;
        if (map[i - 1][j].isBomb == true) map[i][j].nextBomb++;
        if (map[i][j + 1].isBomb == true) map[i][j].nextBomb++;
        if (map[i][j - 1].isBomb == true) map[i][j].nextBomb++;
        if (map[i + 1][j + 1].isBomb == true) map[i][j].nextBomb++;
        if (map[i + 1][j - 1].isBomb == true) map[i][j].nextBomb++;
        if (map[i - 1][j + 1].isBomb == true) map[i][j].nextBomb++;
        if (map[i - 1][j - 1].isBomb == true) map[i][j].nextBomb++;
    }


    void Show(Map map){

    }

    void SearchSurroudings(Map map){

    }
}
