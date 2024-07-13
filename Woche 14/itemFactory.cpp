#include "itemFactory.h"
#include "itemTypes.h"
#include "Label.h"
#include "Button.h"
#include "CheckButton.h"
#include "TextBox.h"
#include "HexBox.h"

#define DEF_NAME "EMPTY NAME"

Item* itemFactory(ItemType type, float height, float width)
{
    if (type == ItemType::Label)
    {
        return new Label(DEF_NAME, height, width);
    }
    else if (type == ItemType::Button)
    {
        return new Button(DEF_NAME, height, width);
    }
    else if (type == ItemType::CheckButton)
    {
        return new CheckButton(DEF_NAME, height, width);
    }
    else if (type == ItemType::TextBox)
    {
        return new TextBox(DEF_NAME, height, width);
    }
    else if (type == ItemType::HexBox)
    {
        return new HexBox(DEF_NAME, height, width);
    }

    return nullptr;
}
