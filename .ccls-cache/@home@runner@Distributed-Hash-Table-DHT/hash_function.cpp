#include <iostream>
#include <string>

// Função de hashing simples usando Folding
int hashFunction(const std::string& key, int tableSize) {
    int hashValue = 0;
    for (char ch : key) {
        hashValue += ch;
    }
    return hashValue % tableSize;
}

int main() {
    // Tamanho da tabela hash
    int tableSize = 10;

    // Chaves de exemplo
    std::string key1 = "apple";
    std::string key2 = "banana";
    std::string key3 = "orange";

    // Calcula o hash para cada chave e imprime o resultado
    std::cout << "Hash para '" << key1 << "': " << hashFunction(key1, tableSize) << std::endl;
    std::cout << "Hash para '" << key2 << "': " << hashFunction(key2, tableSize) << std::endl;
    std::cout << "Hash para '" << key3 << "': " << hashFunction(key3, tableSize) << std::endl;

    return 0;
}
