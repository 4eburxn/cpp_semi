#include<vector>

#ifndef _LOGIC_ELEMENT_H_
#define _LOGIC_ELEMENT_H_

class Logic_Element{
public:
    enum Type{input,output,logic_or,logic_and};
    Type type_of_element; // Тип логического элемента;

private:
    std::vector<Logic_Element&> outputs; // Набор связанных выходом элементов;
    std::vector<Logic_Element&> inputs_std; // Набор связанных входом элементов;
    std::vector<Logic_Element&> inputs_inverted; // Набор связанных инвертированных входом элементов;
    
    void change_state(bool new_state, bool callback_active = false);
    bool current_state; // текущее изходящее состояние
    bool is_inverted = false; // инвертированость выхода
    
    void callback(); // вызов изменения следующих
public:
    

    Logic_Element(Logic_Element::Type, bool is_inverted_ = false);

    void look_for_changes(bool callback_active = false);
    void add_input(Logic_Element, bool is_inverted_input);
    void add_output(Logic_Element);


    bool get_cut_state(); // get value of current_state
};

#endif // _LOGIC_ELEMENT_H_