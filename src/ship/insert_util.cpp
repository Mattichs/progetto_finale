/* 
    BASTIANELLO MATTIA
*/
#include "../include/ship/insert_util.h"

corazzata create_corazzata(defense_grid& dg, std::vector<std::string>& out) {
    bool status = false;
    coords rnd;
    asset rnd_asset;
    corazzata c;
    // loop until ship position is valid
    while(!status) {
            try { 
                rnd = generate_rnd_coords();
                rnd_asset = generate_rnd_asset();
                c = corazzata(rnd_asset,rnd); 
                dg.insert_ship(c);
                out.push_back(get_prow_stern(rnd, rnd_asset, c.get_alias()));
                status = true;
            } catch(std::invalid_argument e) {
                //std::cout << e.what() << std::endl;
            }
    }
    return c;  
}

supporto create_supporto(defense_grid& dg, std::vector<std::string>& out) {
    bool status = false;
    coords rnd;
    asset rnd_asset;
    supporto s;
    // loop until ship position is valid
    while(!status) {
        try { 
            rnd = generate_rnd_coords();
            rnd_asset = generate_rnd_asset();
            s = supporto(rnd_asset,rnd);
            dg.insert_ship(s); 
            out.push_back(get_prow_stern(rnd, rnd_asset, s.get_alias()));
            status = true;
        } catch(std::invalid_argument e) {
            //std::cout << e.what() << std::endl;
        }
    }
    return s;
}


esploratore create_esploratore(defense_grid& dg, std::vector<std::string>& out) {
    bool status = false;
    coords rnd;
    asset rnd_asset;
    esploratore e;
    // loop until ship position is valid
    while(!status) {
        try { 
            rnd = generate_rnd_coords();
            e = esploratore(rnd); 
            dg.insert_ship(e);
            out.push_back(get_prow_stern(rnd, rnd_asset, e.get_alias()));
            status = true;
        } catch(std::invalid_argument e) {
            //std::cout << e.what() << std::endl;
        }
    }
    return e;
}


corazzata insert_corazzata(std::string messaggio, defense_grid& dg, std::vector<std::string>& out)  {
    bool status = false;
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    corazzata c;
    // loop until ship position is valid
    while(!status) {
        try {
            std::cout << "Inserisci posizione corazzata nr." << messaggio << std::endl;
            std::getline(std::cin, s);
            coords_vec = coords_translation(s);
            center = get_center(coords_vec);
            // ottengo e controllo
            a = get_asset(coords_vec, 'c');
            c = corazzata(a, center); 
            dg.insert_ship(c);
            out.push_back(s += "\n");
            status = true;
        }
        catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return c;
}
supporto insert_supporto(std::string messaggio, defense_grid& dg, std::vector<std::string>& out)  {
    bool status = false;
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    supporto supp;
    // loop util ship position is valid
    while(!status) {
        try {
            std::cout << "Inserisci posizione supporto nr." << messaggio << std::endl;
            std::getline(std::cin, s);
            coords_vec = coords_translation(s);
            // ottengo e controllo
            a = get_asset(coords_vec, 's');
            center = get_center(coords_vec);
            supp = supporto(a, center); 
            dg.insert_ship(supp);
            out.push_back(s+= "\n");
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return supp;
}
esploratore insert_esploratore(std::string messaggio, defense_grid& dg, std::vector<std::string>& out)  {
    bool status = false;
    std::string s;
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    esploratore e;
    // loop until ship position is valid
    while(!status) {
        try {
            std::cout << "Inserisci posizione supporto nr." << messaggio << std::endl;
            std::getline(std::cin, s);
            coords_vec = coords_translation(s);
            // ottengo e controllo
            a = get_asset(coords_vec, 'e');
            center = get_center(coords_vec);
            e = esploratore( center); 
            dg.insert_ship(e);
            out.push_back(s += "\n");
            status = true;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return e;
}



corazzata insert_corazzata(defense_grid& dg, std::string s)  {
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    // get two coords in std::vector
    coords_vec = coords_translation(s);
    // get asset
    a = get_asset(coords_vec, 'c');
    // get center
    center = get_center(coords_vec);
    corazzata c = corazzata(a, center); 
    dg.insert_ship(c);
    return c;
}

supporto insert_supporto(defense_grid& dg, std::string s)  {
    std::vector<coords> coords_vec;
    coords center;
    asset a;
    // get two coords in std::vector
    coords_vec = coords_translation(s);
    // get asset
    a = get_asset(coords_vec, 's');
    // get center
    center = get_center(coords_vec);
    supporto supp = supporto(a, center); 
    dg.insert_ship(supp);
    return supp;
}

esploratore insert_esploratore(defense_grid& dg, std::string s)  {
    std::vector<coords> coords_vec;
    coords center;
    // get two coords in std::vector
    coords_vec = coords_translation(s);
    // get center
    center = get_center(coords_vec);
    esploratore e = esploratore(center); 
    dg.insert_ship(e);
    return e;
}