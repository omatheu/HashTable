#include <iostream>
#include <unordered_map>
#include <chrono>

int main() {
    // Criação e preenchimento da tabela hash
    std::unordered_map<int, std::string> tabelaHash;
    for (int i = 0; i < 1000000; ++i) {
        tabelaHash[i] = "valor" + std::to_string(i);
    }

    // Chave para pesquisa
    int chave = 500000;

    // Medição do tempo de pesquisa
    auto start = std::chrono::high_resolution_clock::now();

    // Pesquisa pela chave na tabela hash
    auto it = tabelaHash.find(chave);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Verifica se a chave foi encontrada
    if (it != tabelaHash.end()) {
        std::cout << "Chave encontrada! Valor: " << it->second << std::endl;
    } else {
        std::cout << "Chave não encontrada!" << std::endl;
    }

    // Imprime o tempo de pesquisa
    std::cout << "Tempo de pesquisa: " << duration.count() << " microssegundos" << std::endl;

    return 0;
}
