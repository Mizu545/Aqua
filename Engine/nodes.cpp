AQUA_NAMESPACE_OPEN_SCOPE

namespace {
    template<typename DstType> DstType convertToAqua(const VtValue &value)
    {
        if (value.IsHolding<DstType>()){
            return value.UncheckedGet<DstType>();
        }
    }
}
