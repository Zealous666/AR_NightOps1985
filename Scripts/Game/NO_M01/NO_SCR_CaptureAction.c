//Custom script by Zeal to capture a vehicle as a objective via action

class NO_SCR_CaptureAction : ScriptedUserAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		//Finish current task
		IEntity taskEntity3 = GetGame().GetWorld().FindEntityByName("m01_tsk_3");
        NO_SCR_EditorTask task3 = NO_SCR_EditorTask.Cast(taskEntity3);
		task3.ChangeStateOfTask(TriggerType.Finish);
		
		/*
		//Unlock exfil task
		IEntity taskEntityX = GetGame().GetWorld().FindEntityByName("m01_tsk_x");
        NO_SCR_EditorTask taskX = NO_SCR_EditorTask.Cast(taskEntityX);
		//taskX.ChangeStateOfTask(TriggerType.Create);
		taskX.ChangeStateOfTask(TriggerType.Assign);
		*/
		
		/*
		//Enables exfil scenario-end trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("tsk_main_x_trg"));
			if(trigger)
			trigger.SetActive(true);
		*/
		
		//Removes encryption key
		SCR_EntityHelper.DeleteEntityAndChildren(pOwnerEntity);
	}

}