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
template<>float3 convertToAqua<float3>(const VtValue &value)
    {
        if(value.IsHolding<GfVec3f>()){
            const GfVec3f convertedValue = value.UncheckedGet<GfVec3f>()
            return make_float3(convertedValue[0], convertedValue[1], convertedValue[2]);
        }
        if (value.IsHolding<GfVec4f>()){
            const GfVec4f convertedValue = Value.UncheckedGet<GfVec4f>()
            return make_float3(convertedValue[0], convertedValue[1], convertedValue[2]);
        }
        if (value.CanCast<GfVec3f>()){
            const GfVec3f convertedValue = VtValue::Cast<GfVec3f>(value).UncheckedGet<GfVec3f>();
            return make_float3(convertedValue[0], convertedValue[1], convertedValue[2]);
        }
        if (value.CanCast<GfVec4f>()){
            const GfVec4f convertedValue = VtValue::Cast<GfVec4f>(value).UncheckedGet<GfVec4f>();
            return make_float3(convertedValue[0], convertedValue[1], convertedValue[2]);
        }

        TF_WARN("Could not convert VtValue to float3");
        return zero_float3();
    }
template<> ustring convertToAqua<ustring>(const VtValue &value)
    {
        if (value.IsHolding<TfToken>()){
            return ustring(value.UncheckedGet<TfToken>().GetString());
        }
        if (value.IsHolding<std::string>()){
            return ustring(value.UncheckedGet<std::string>());
        }
        if (value.IsHolding<SdfAssetPath>()){
            const SdfAssetPath &path = value.UncheckedGet<SdfAssetPath>();
            return ustring(path.GetResolvedPath());
        }
        if (value.CanCast<TfToken>()){
            return convertToAqua<ustring>(VtValue::Cast<TfToken>(value));
        }
        if (value.CanCast<std::string>()){
            return convertToAqua<ustring>(VtValue::Cast<std::string>(value));
        }
        if (value.CanCast<SdfAssetPath>()){
            return convertToAqua<ustring>(VtValue::Cast<SdfAssetPath>(value));
        }
        
        TF_WARN("Could not convert VtValue to ustring");
        return ustring();
    }

}
