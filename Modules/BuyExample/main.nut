
local { Game } = require("HeatedMetal")
local math = require("math")

local bServer = Game.IsHost();

local LocalData = {
    money = 200
};

local NetworkName = "BuyExample"

// Server Data
local UserData = [];

function BuyServerIml(Sender)
{
    if(!bServer) return;

    local money = 0;

    foreach(info in UserData)
    {
        if(info.player == Sender)
        {
            info.money = math.clamp(info.money - 50, 0, 9999)
            money = info.money
            break;
        }
    }

    print("New User Money: " + money)

    local Data = {
        Type = "buyr"
        money = money
    };

    SendNetworkTable(NetworkName, Data, Sender);
}

function BuyRspImpl(Table)
{
    LocalData.money = Table.money

    print("RSP new Money: " + Table.money)
}

function Network(Name, Table, Sender)
{
    if(Name != NetworkName) return;

    switch (Table.Type) {
        case "buy":
        {
            BuyServerIml(Sender)
            break;
        }
        case "buyr":
        {
            BuyRspImpl(Table)
            break;
        }

        default:
        break;
    }
}

AddCallback_NetworkTable(Network)

if(bServer)
{
    // Add 200 money for each player
    foreach(player in Game.GetPlayerList())
    {
        local Data = {
            player = player,
            money = 200
        }
        UserData.append(Data)
    }
}

function buy(args)
{
    local Data = {
        Type = "buy"
    };

    SendNetworkTable(NetworkName, Data);
}

RegisterCommand(buy, "buy", "", "test buy")