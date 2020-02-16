import java.util.Random;
import java.util.concurrent.BlockingQueue; // para concorrencia
import java.util.concurrent.ArrayBlockingQueue;	// para concorrencia 

class ProdutorConsumidor {
  static class Produtor extends Thread {
    int id;
    BlockingQueue<Integer> queue;

    Produtor(int id, BlockingQueue<Integer> queue) { // construtor
      this.id = id;
      this.queue = queue;
    }

    @Override	// sobreescrevendo !
    public void run() {
      Random random = new Random();
      while (true) {
        try {
          System.out.printf(":::::::PRODUTOR %d PRODUZIU E VAI COLOCAR NA FILA!\n", id);
          queue.put(id);
          System.out.printf(":::::::PRODUTOR %d COLOCOU NA FILA!\n", id);
          int tempoMs = 1000 + random.nextInt(4000);
          Thread.sleep(tempoMs);
        }
				catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
    }
  }

  static class Consumidor extends Thread {
    int id;
    BlockingQueue<Integer> queue;

    Consumidor(int id, BlockingQueue<Integer> queue) { // construtor
      this.id = id;
      this.queue = queue;
    }

    @Override	// sobreescrita
    public void run() {
      Random random = new Random();
      while (true) {
        try {
          System.out.printf("			>>>>>>>> Consumidor %d vai pegar um item da fila!\n", id);
          int x = queue.take();
          System.out.printf("			>>>>>>>> Consumidor %d pegou um item do produtor %d!\n", id, x);
          int tempoMs = 1000 + random.nextInt(4000);
          Thread.sleep(tempoMs);
        }
        catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
    }
  }


  public static void main(String[] args) {
    final int n = 3;
    
    BlockingQueue<Integer> queue = new ArrayBlockingQueue<Integer>(10);
    Produtor[] produtor = new Produtor[n];
		Consumidor[] consumidor = new Consumidor[n];    
		
    for (int i = 0; i < n; ++i) {
      produtor[i] = new Produtor(i + 1, queue);
      produtor[i].start();
    }
    for (int i = 0; i < n; ++i) {
      consumidor[i] = new Consumidor(i + 1, queue);
      consumidor[i].start();
    }
  }
  
}
