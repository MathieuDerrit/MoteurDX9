// Définir les entrées et sorties
struct VS_OUTPUT
{
    float4 Position : POSITION;
    float2 TexCoord : TEXCOORD0;
};

struct PS_OUTPUT
{
    float4 Color : COLOR0;
};

sampler2D g_Texture;
PS_OUTPUT main(VS_OUTPUT In)
{
    PS_OUTPUT Out = (PS_OUTPUT)0;
    Out.Color = tex2D(g_Texture, In.TexCoord);
    return Out;
}

// Modifier la saturation, la luminosité et le contraste
float3 ModifySaturation(float4 Color, float Saturation)
{
    float3 intensity = dot(Color.rgb, float3(0.299, 0.587, 0.114));
    return lerp(intensity, Color.rgb, Saturation);
}

float4 ModifyBrightness(float4 Color, float Brightness)
{
    return Color + Brightness;
}

float4 ModifyContrast(float4 Color, float Contrast)
{
    return saturate((Color - 0.5) * Contrast + 0.5);
}

PS_OUTPUT postProcessMain(VS_OUTPUT In)
{
    PS_OUTPUT Out = (PS_OUTPUT)0;
    float4 color = tex2D(g_Texture, In.TexCoord);
    color = ModifySaturation(color, Saturation);
    color = ModifyBrightness(color, Brightness);
    color = ModifyContrast(color, Contrast);
    Out.Color = color;
    return Out;
}
