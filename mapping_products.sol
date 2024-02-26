// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;

contract Products {
    struct Product {
        string name;
        uint price;
    }
    
    mapping(address => Product) public productMapping;
    address[] public productAddresses;

    
    function adding_values() public {
    Product storage produto = productMapping[productAddresses[0]];

    produto.name = "Caneta BIC";
    produto.price = 88;

    productAddresses.push(0x);
    }

    function get_products_address () view public returns (address[] memory) {
        return productAddresses;
    }
}