

function ZoomIn(WeaponComponent)
{
    print("Zooming In " + WeaponComponent.Name + "| " + WeaponComponent.Entity)
}

function ZoomOut(WeaponComponent)
{
    print("Zooming Out | " + WeaponComponent.Name + "| " + WeaponComponent.Entity)
}

function Fire(WeaponComponent)
{
    print("Firing " + WeaponComponent.Name + "| " + WeaponComponent.Entity)
}

function FireStop(WeaponComponent)
{
    print("FiringStop | " + WeaponComponent.Name + "| " + WeaponComponent.Entity)
}

AddCallback_WeaponZoomIn(ZoomIn)
AddCallback_WeaponZoomOut(ZoomOut)

AddCallback_WeaponFire(Fire)
AddCallback_WeaponFireStop(FireStop)
