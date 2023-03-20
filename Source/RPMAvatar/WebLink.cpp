#include "WebLink.h"

void UWebLink::AvatarGenerated(FString JsonResponse)
{
	//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Yellow, FString::Printf(TEXT("AvatarGenerated() in WebLink.cpp")));
	//UE_LOG(LogTemp, Warning, TEXT("AvatarGenerated() in WebLink.cpp"));

	FString Url = "";
	if (JsonResponse.Contains(TEXT(".glb")))
	{
		UE_LOG(LogTemp, Warning, TEXT(".glb found "));
		Url = JsonResponse;
	}
	if (Url.IsEmpty())
	{
		return;
	}
	//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Yellow, FString::Printf(TEXT("AvatarGenerated() in WebLink.cpp,  %s"),*Url));
	//UE_LOG(LogTemp, Warning, TEXT("AvatarGenerated() in WebLink.cpp, %s"),*Url);

	WebBrowserResponse.Execute(Url);
	LastAvatarUrl = Url;
}

void UWebLink::SetAvatarUrlCallback(const FReadyPlayerWebBrowserResponse& WebBrowserCallback)
{
	//Calls AvatarGeneratedCallback events in WBP_RPM_Browser
	WebBrowserResponse = WebBrowserCallback;
}

FString UWebLink::GetLastAvatarUrl()
{
	return LastAvatarUrl;
}

