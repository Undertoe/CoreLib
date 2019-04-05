#include "vmemodes.hh"

std::string Terryn::ToString(Terryn::VMEAddressMode m)
{
    switch (m)
    {
    case VMEAddressMode::A16:
        return "a16";
    case VMEAddressMode::A24:
        return "a24";
    case VMEAddressMode::A32:
        return "a32";
    case VMEAddressMode::A64:
        return "a64";
    default:
        return "UNKNOWN";
    }

}


std::string Terryn::ToString(Terryn::VMEDataWidth m)
{
    switch (m)
    {
    case VMEDataWidth::D8:
        return "d8";
    case VMEDataWidth::D16:
        return "d16";
    case VMEDataWidth::D32:
        return "d32";
    case VMEDataWidth::D64:
        return "d64";
    default:
        return "UNKNOWN";
    }

}
