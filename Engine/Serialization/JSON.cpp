#include "../JSON.h"
#include "rapidjson/istreamwrapper.h"
#include "../Core/Logger.h"
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include <fstream>


namespace neu::json
{
    bool Load(const std::string& filename, rapidjson::Document& document)
    {
        std::ifstream stream;

        rapidjson::IStreamWrapper istream(stream);
        document.ParseStream(istream);
        if (document.IsObject() == false)
        {
            return false;
        }

        return true;
    }

    bool Get(const rapidjson::Value& value, const std::string& name, int& data)
    {

        if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsInt() == false)
        {
           return false;
        }

        data = value[name.c_str()].GetInt();

        return true;
    }

    bool Get(const rapidjson::Value& value, const std::string& name, float& data)
    {
        if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsFloat() == false)
        {
            return false;
        }

        data = value[name.c_str()].GetFloat();

        return true;
    }

    bool Get(const rapidjson::Value& value, const std::string& name, bool& data)
    {
        if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsBool() == false)
        {
            return false;
        }

        data = value[name.c_str()].GetBool();

        return true;
    }

    bool Get(const rapidjson::Value& value, const std::string& name, std::string& data)
    {
        if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsString() == false)
        {
            return false;
        }

        data = value[name.c_str()].GetString();

        return true;
    }

    bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data)
    {
        if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false || value[name.c_str()].Size() != 2)
        {
            return false;

        }

        // create json array object 
        auto& array = value[name.c_str()];
        for (rapidjson::SizeType i = 0; i < array.Size(); i++)
        {
            if (!array[i].IsInt())
            {
                return false;
            }

            data[i] = array[i].GetInt();
        }

        return true;
    }

    bool Get(const rapidjson::Value& value, const std::string& name, Color& data)
    {
        if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false || value[name.c_str()].Size() != 4)
        {
           return false;

        }

        // create json array object 
        auto& array = value[name.c_str()];
        for (rapidjson::SizeType i = 0; i < array.Size(); i++)
        {
            if (!array[i].IsFloat())
            {
                return false;
            }

            data[i] = array[i].GetInt();
        }

        return true;
    }

}