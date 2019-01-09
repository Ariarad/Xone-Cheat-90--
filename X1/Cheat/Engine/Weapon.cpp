#include "Weapon.h"
#include  "../Initialize/Offsets.h"
namespace Engine
{
//[junk_enable /]
	int CBaseWeapon::GetWeaponId()
	{
		typedef int( __thiscall* GetWeaponIDFn )( void* );
		return GetMethod<GetWeaponIDFn>( this , 263/*458*/ )( this );
	}


	int	CBaseWeapon::GetWeaponType()
	{
		typedef int( __thiscall* GetWeaponTypeFn )( void* );
		return GetMethod<GetWeaponTypeFn>( this , 453 )( this );
	}


	int CBaseWeapon::GetWeaponAmmo()
	{
		return *(PINT)( ( DWORD )this + offsets["m_iClip1"]);
	}

	float CBaseWeapon::GetInaccuracy()
	{	
		if (IsBadReadPtr(this, sizeof(CBaseWeapon)))
			return 0;

		typedef float(__thiscall* OriginalFn)(void*);


		if (IsBadReadPtr((*(OriginalFn**)this), sizeof(CBaseWeapon)))
			return 0;

		if (IsBadCodePtr((FARPROC)(PDWORD)(*(OriginalFn**)this)[467]))
		{	
			return 0;
		}
		
		if (IsBadReadPtr((*(OriginalFn**)this)[467], sizeof(OriginalFn)))
			return 0;

		return GetVFunc<OriginalFn>(this, 467)(this);
	}
	HANDLE* CBaseWeapon::GetWeaponWorldModel()
	{
		return (HANDLE*)((DWORD)this + offsets["m_hWeaponWorldModel"]);
	}
	int* CBaseWeapon::ModelIndex()
	{
		return (int*)((uintptr_t)this + offsets["m_nModelIndex"]);
	}
	int* CBaseWeapon::ViewModelIndex()
	{
		return (int*)((uintptr_t)this + offsets["m_iViewModelIndex"]);
	}
	int* CBaseWeapon::fixItemIDHigh()
	{
		return (int*)((uintptr_t)this + 0x2FB0);
	}
	short* CBaseWeapon::fixskins()
	{
		return (short*)((uintptr_t)this + offsets["m_iItemDefinitionIndex"]);
	}
	int* CBaseWeapon::GetEntityQuality()
	{
		return (int*)((uintptr_t)this + 0x2F9C);
	}
	int* CBaseWeapon::OwnerXuidLow()
	{
		return (int*)((uintptr_t)this + 0x31A0);
	}
	int* CBaseWeapon::OwnerXuidHigh()
	{
		return (int*)((uintptr_t)this + 0x31A4);
	}

	int CBaseWeapon::GetWeaponAmmoClp2()
	{
		return *(PINT)((DWORD)this + offsets["m_iClip2"]);
	}

	int	CBaseWeapon::GetZoomLevel()
	{
		if (!this)
			return 0;

		if (IsBadReadPtr(this, sizeof(CBaseWeapon)))
			return 0;


		return *(PINT)( ( DWORD )this + offsets["m_zoomLevel"]);
	}

	bool CBaseWeapon::GetWeaponReload()
	{
		return *(bool*)( ( DWORD )this + offsets["m_bCanReload"]);
	}

	float CBaseWeapon::GetNextPrimaryAttack()
	{
		return *(float*)( ( DWORD )this + offsets["m_flNextPrimaryAttack"]);
	}

	CWeaponInfo* CBaseWeapon::GetWeaponInfo()
	{
		typedef CWeaponInfo*( __thiscall* GetWeaponDataFn )( void* );
		return GetMethod< GetWeaponDataFn >( this , /*445*/448 )( this );
	}

	CBaseAttributableItem* CBaseWeapon::GeteAttributableItem()
	{
		return (CBaseAttributableItem*)( DWORD )this;

	}

	const char*	CBaseWeapon::GetName()
	{
		if (IsBadReadPtr(this, sizeof(CBaseWeapon)))
			return "";

		typedef const char* ( __thiscall* GetNameFn )( void* );


		return GetMethod<GetNameFn>( this , 376 )( this );
	}

	const char*	CBaseWeapon::GetPrintName()
	{
		typedef const char* ( __thiscall* GetPrintNameFn )( void* );
		return GetMethod<GetPrintNameFn>( this , 379 )( this );
	}

	short* CBaseAttributableItem::GetItemDefinitionIndex()
	{
		// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iItemDefinitionIndex
		return (short*)( ( DWORD )this + offsets["m_iItemDefinitionIndex"]);
	}

	int* CBaseAttributableItem::GetIndex()
	{
		// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iItemDefinitionIndex
		return (int*)((DWORD)this + offsets["m_bIsAutoaimTarget"]);
	}

	int* CBaseAttributableItem::ModelIndex()
	{
		return (int*)((uintptr_t)this + offsets["m_nModelIndex"]);
	}
	int* CBaseAttributableItem::ViewModelIndex()
	{
		return (int*)((uintptr_t)this + offsets["m_iViewModelIndex"]);
	}

	int* CBaseAttributableItem::GetItemIDHigh()
	{
		// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iItemIDHigh
		return (int*)( ( DWORD )this + offsets["m_iItemIDHigh"]);
	}

	int* CBaseAttributableItem::fixItemIDHigh()
	{
		return (int*)((uintptr_t)this + 0x2FB0);
	}

	int* CBaseAttributableItem::GetAccountID()
	{
		// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iAccountID
		return (int*)( ( DWORD )this + offsets["m_iAccountID"]);
	}

	int* CBaseAttributableItem::GetEntityQuality()
	{
		// DT_BaseAttributableItem -> m_AttributeManager -> m_Item -> m_iEntityQuality
		return (int*)( ( DWORD )this + offsets["m_iEntityQuality"]);
	}

	int* CBaseAttributableItem::GetOriginalOwnerXuidLow()
	{
		// DT_BaseAttributableItem -> m_OriginalOwnerXuidLow
		return (int*)( ( DWORD )this + offsets["m_OriginalOwnerXuidLow"]);
	}

	int* CBaseAttributableItem::GetOriginalOwnerXuidHigh()
	{
		// DT_BaseAttributableItem -> m_OriginalOwnerXuidHigh
		return (int*)( ( DWORD )this + offsets["m_OriginalOwnerXuidHigh"]);
	}

	int* CBaseAttributableItem::GetFallbackPaintKit()
	{
		// DT_BaseAttributableItem -> m_nFallbackPaintKit
		return (int*)( ( DWORD )this + offsets["m_nFallbackPaintKit"]);
	}

	float* CBaseAttributableItem::GetFallbackWear()
	{
		// DT_BaseAttributableItem -> m_flFallbackWear
		return (float*)( ( DWORD )this + offsets["m_flFallbackWear"]);
	}

	int* CBaseAttributableItem::GetFallbackSeed()
	{
		// DT_BaseAttributableItem -> m_nFallbackSeed
		return (int*)( ( DWORD )this + offsets["m_nFallbackSeed"]);
	}

	int* CBaseAttributableItem::GetFallbackStatTrak()
	{
		// DT_BaseAttributableItem -> m_nFallbackStatTrak
		return (int*)( ( DWORD )this + offsets["m_nFallbackStatTrak"]);
	}

	char* CBaseAttributableItem::GetCustomName() {
		return reinterpret_cast<char*>(uintptr_t(this) + offsets["m_szCustomName"]);
	}

	CBaseViewModel* CBaseAttributableItem::GetViewModel()
	{
		return (CBaseViewModel*)( DWORD )this;
	}

}     