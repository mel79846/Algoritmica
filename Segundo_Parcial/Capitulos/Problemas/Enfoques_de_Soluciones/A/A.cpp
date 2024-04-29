import java.util.Scanner; 

public class Main { 

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in); // crea un objeto Scanner para leer datos desde la entrada estándar

        int N = scanner.nextInt(); // lee el número de casos de prueba y lo almacena en la variable "N"

        for (int dataset = 1; dataset <= N; dataset++) { // este ciclo for se repite "N" veces, una vez por cada caso de prueba

            double[] balances = new double[12]; // crea un arreglo de dobles de tamaño 12 para almacenar los saldos mensuales
            double sum = 0; // inicializa la variable "sum" a cero para calcular la suma de los saldos mensuales

            for (int i = 0; i < 12; i++) { // este ciclo for se repite 12 veces, una vez por cada mes

                balances[i] = scanner.nextDouble(); // lee el saldo mensual y lo almacena en el arreglo "balances"
                sum += balances[i]; // suma el saldo mensual a la variable "sum"
            }

            double average = sum / 12; // calcula el promedio de los saldos mensuales dividiendo la suma por 12
            System.out.printf("%d $%,.2f%n", dataset, average); // imprime el número del caso de prueba y el promedio de los saldos mensuales con dos decimales
        }

        scanner.close(); // cierra el objeto Scanner para liberar recursos del sistema
    }
}
