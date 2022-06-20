//Custom script by Zeal to win the mission once the action is used

class NO_SCR_Sabotage_Action : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Show popup
		SCR_PopUpNotification.GetInstance().PopupMsg("SATCHEL CHARGE PLANTED", duration: 5);
		
		//Show hint
		SCR_HintManagerComponent hintComponent = SCR_HintManagerComponent.GetInstance();
		hintComponent.ShowCustomHint("40 Seconds till satchel explodes", "Satchels placed", 15);
		
 		//Set delay-timer to destroy
    	GetGame().GetCallqueue().CallLater(DelayedHint1, 10000, false);
		
	}

	//Destroy after delay
	protected void DelayedHint1()
	{
		
    SCR_PopUpNotification.GetInstance().PopupMsg("BOOM", duration: 60);
	
	}

}