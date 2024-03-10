# Introduction
This project models a multiplayer role-playing game scenario where a population of players is organized into clans. Each person belongs to a single clan, and individuals can join or leave the game, join or leave a clan, and clans can undergo fusion.

# Person Definition
A person is defined by an identifier (ID), age, and gender ('h' for male, 'f' for female). The project adheres to the following specifications:

# Sortes:

Genre: Character representing gender

Personne: Structure representing a person

# Operations:

h(), f(): Functions returning the gender character

per_mk: Function to create a person

per_id, per_age, per_genre: Accessor functions for ID, age, and gender

# Clans Structure

The clans are implemented using a linked list structure where each clan contains a list of members represented by pointers. The project provides the following structures:

Population: Linked list structure representing the population

Membre: Structure representing a member of the population or a clan

Clans: Linked list structure representing the clans

Jeu: Structure combining the population and clans

# Operations

jeu_vide(): Initializes an empty game.

jeu_adresse_chef(): Returns the address of the chief of a clan from the address of a member.

jeu_print_pop(): Prints the list of players in the game.

jeu_print_clan(): Prints the list of members in a specific clan.

jeu_fusion(): Merges two clans in the game.

jeu_adj_joueur(): Adds a player to the game, creating a new clan for the player.

jeu_sortie_joueur(): Removes a player from the game.

# Usage
The provided main function demonstrates the usage of the implemented functionalities, including creating players, adding them to the game, printing the population, and performing clan operations.