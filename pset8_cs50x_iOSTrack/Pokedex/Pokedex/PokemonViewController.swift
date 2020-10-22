//
//  PokemonViewController.swift
//  Pokedex
//
//  Created by Murat Baykor on 22.10.2020.
//

import UIKit

class PokemonViewController: UIViewController {
    var url: String!

    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var numberLabel: UILabel!
    @IBOutlet var type1Label: UILabel!
    @IBOutlet var type2Label: UILabel!
    @IBOutlet var imageView: UIImageView!
    @IBOutlet var catchButton: UIButton!
    @IBOutlet var textView: UITextView!
    
    var catched: Bool = false
    var imageURL: String?

    func capitalize(text: String) -> String {
        return text.prefix(1).uppercased() + text.dropFirst()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        nameLabel.text = ""
        numberLabel.text = ""
        type1Label.text = ""
        type2Label.text = ""
        textView.text = ""
        catchButton.setTitle("", for: .normal)
        loadPokemon()
        
    }
    
    @IBAction func toggleCatch() {
        catched.toggle()
        setCatchButtonTitle()
        UserDefaults.standard.setValue(catched, forKey: nameLabel.text!.lowercased())
    }
    
    func setCatchButtonTitle() {
        let buttonTitle = catched ? "Release" : "Catch"
        catchButton.setTitle(buttonTitle, for: .normal)
    }
    

    func loadPokemon() {
        URLSession.shared.dataTask(with: URL(string: url)!) { (data, response, error) in
            guard let data = data else {
                return
            }

            do {
                let result = try JSONDecoder().decode(PokemonResult.self, from: data)
                self.catched = UserDefaults.standard.bool(forKey: result.name)
                self.loadDescription(url: result.species.url)
                DispatchQueue.main.async {
                    self.navigationItem.title = self.capitalize(text: result.name)
                    self.nameLabel.text = self.capitalize(text: result.name)
                    self.numberLabel.text = String(format: "#%03d", result.id)
                    self.imageURL = result.sprites.front_default
                    self.imageView.image = self.loadImage(url: result.sprites.front_default)
                    self.setCatchButtonTitle()
                    
                    for typeEntry in result.types {
                        if typeEntry.slot == 1 {
                            self.type1Label.text = typeEntry.type.name
                        }
                        else if typeEntry.slot == 2 {
                            self.type2Label.text = typeEntry.type.name
                        }
                    }
                }
            }
            catch let error {
                print(error)
            }
        }.resume()
    }
    
    func loadDescription(url: String?) {
        guard let url = url else { return }
       
        URLSession.shared.dataTask(with: URL(string: url)!) { (data, response, error) in
            guard let data = data else { return }

            do {
                let description = try JSONDecoder().decode(PokemonDescription.self, from: data)

                DispatchQueue.main.async {
                    self.textView.text = description.flavor_text_entries.first(where: { $0.language.name == "en" })?.flavor_text.replacingOccurrences(of: "\n|\u{0C}", with: " ", options: .regularExpression)
                }
            }
            catch let error {
                print(error)
            }
            
            
        }.resume()
        
        
        
    }
    
    
    func loadImage(url: String) -> UIImage? {
        guard let imageURL = imageURL else { return nil }
        
        guard let URL = URL(string: imageURL) else { return nil }
        
        let imageData = try? Data(contentsOf: URL)
        
        if let imageData = imageData {
            return UIImage(data: imageData)
        }
        else {
            return nil
        }
    }
}
