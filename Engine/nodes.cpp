AQUA_NAMESPACE_OPEN_SCOPE

namespace {
    template<typename DstType> DstType convertToAqua(const VtValue &value)
    {
        if (value.IsHolding<DstType>()){
            return value.UncheckedGet<DstType>();
        }
        const VtValue castedValue = VtValue::Cast<DstType>(value);
        if (castedValue.IsHolding<DstType>()) {
            return castedValue.IsHolding<DstType>();
        }
        TF_WARN("Could not convert value to Aqua type");
    }
}
