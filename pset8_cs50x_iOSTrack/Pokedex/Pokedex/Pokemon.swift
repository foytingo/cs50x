//
//  Pokemon.swift
//  Pokedex
//
//  Created by Murat Baykor on 22.10.2020.
//

import Foundation

struct PokemonListResults: Codable {
    let results: [PokemonListResult]
}

struct PokemonListResult: Codable {
    let name: String
    let url: String
}

struct PokemonResult: Codable {
    let id: Int
    let name: String
    let types: [PokemonTypeEntry]
    let sprites: PokemonSprite
    let species: PokemonSpecies

}

struct PokemonTypeEntry: Codable {
    let slot: Int
    let type: PokemonType
}

struct PokemonType: Codable {
    let name: String
}

struct PokemonSprite: Codable {
    let front_default: String
}

struct PokemonSpecies: Codable {
    let url: String
}

struct PokemonDescription: Codable {
    let flavor_text_entries: [PokemonText]
}

struct PokemonText: Codable {
    let flavor_text: String
    let language: Language
}

struct Language: Codable {
    let name: String
}
