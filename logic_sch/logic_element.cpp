#include "lgic_element.h"

Logic_Element::Logic_Element(Logic_Element::Type type_of_element_, bool is_inverted_) : type_of_element{type_of_element_}, is_inverted{is_inverted_}{}

void Logic_Element::look_for_changes(bool callback_active)
{
    bool calc_state;
    if(type_of_element = Logic_Element::Type::logic_or){ // проверка для подсчет изменения для logic_or
        calc_state = false;
        for(auto& element:inputs_std){
            if(element.get_current_state()){
                calc_state = true;
            }
            break;
        }
        if(!calc_state){
            for(auto& element:inputs_inverted){
                if(!element.get_current_state()){
                    calc_state = true;
                }
                break;
            }
        }
        if(calc_state!=get_cut_state()){
            change_state(calc_state, callback_active);
        }
    }
    else if(type_of_element = Logic_Element::Type::logic_and){
        calc_state = true;
        for(auto& element:inputs_std){
            if(!element.get_current_state()){
                calc_state = false;
                break;
            }
        }
        if(!calc_state){
            for(auto& element:inputs_inverted){
                if(element.get_current_state()){
                    calc_state = false;
                    break;
                }
            }
        }

        if(calc_state!=get_cut_state()){
            change_state(calc_state, callback_active);
        }
    }
}

void Logic_Element::change_state(bool new_state, bool callback_active /*= false*/)
{
    current_state = new_state;
    if(callback_active){
        callback();
    }
    else{
        for(auto &element:inputs_std){
            element.look_for_changes(false);
        }
        for(auto &element:inputs_inverted){
            element.look_for_changes(false);
        }
    }
}

/// @brief Returns current state of logic element
/// @return bool state
bool Logic_Element::get_cut_state(){
    if(is_inverted){
        return !current_state;
    }
    return current_state;
}






