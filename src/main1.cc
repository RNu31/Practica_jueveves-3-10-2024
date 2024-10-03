#include <iostream>
#include <sstream> // para entrada y salida de cadenas usando flujo de datos 
#include <stack>
#include <string> 

// 3 4 + 2 * 7 /

double EvaluarExpresion(std::stack<double>& operadores, const std::string& expresion);

int main(int argc, char *argv[]) {
  double resultado;
  std::stack<double> operadores;

  std::string expresion;
  std::cout << "Ingresa la expresion en formato postfijo: " << std::endl;
  std::getline(std::cin, expresion);

  resultado = EvaluarExpresion(operadores, expresion);

  // Verifica si hubo un error en la evaluación
  if (resultado == -1) {
    std::cout << "Error en la evaluacin de la expresion." << std::endl;
  } else {
    std::cout << "Resultado: " << resultado << std::endl;
  }
  return 0;
}

double EvaluarExpresion(std::stack<double>& operadores, const std::string& expresion) {
  double derecha, izquierda;
  std::istringstream tokens(expresion);  // Permite leer datos de una cadena como si fuera un flujo de entrada.
  std::string token;

  // Leer y evaluar en un solo paso
  while (tokens >> token) {
    if (isdigit(token[0])) {              // Si el token es un número
      operadores.push(std::stod(token));  // std::stod convierte la cadena de texto en valores tipo double
    } else {                              // Si el token es un operador
      if (operadores.size() < 2) {
        std::cout << "Error: Numero insuficiente de operandos" << std::endl;
        return -1;  // Indica error
      }

      derecha = operadores.top();
      operadores.pop();
      izquierda = operadores.top();
      operadores.pop();

      switch (token[0]) {
        case '+':
          operadores.push(izquierda + derecha);
          break;
        case '-':
          operadores.push(izquierda - derecha);
          break;
        case '*':
          operadores.push(izquierda * derecha);
          break;
        case '/':
          if (derecha == 0) {
            std::cout << "Error: Division por cero" << std::endl;
            return -1;  // Indica error
          }
          operadores.push(izquierda / derecha);
          break;
        default:
          std::cout << "Error: Operador desconocido" << std::endl;
          return -1;  // Indica error
      }
    }
  }

  // Al final, debería quedar un solo resultado en la pila
  if (operadores.size() != 1) {
    std::cout << "Error: Expresion no valida" << std::endl;
    return -1;  // Indica error
  }

  return operadores.top();  // Devuelve el resultado final
}