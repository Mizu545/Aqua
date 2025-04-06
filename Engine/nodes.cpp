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

template<> float2 convertToAqua<float2>(const VtValue &value)
    {
        const GfVec2f convertedValue = convertToAqua<GfVec2f>(value);
        return make_float2(convertedValue[0], convertedValue[1]);
    }

}
