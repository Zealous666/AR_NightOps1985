//Custom script by Zeal to start the intel operation in Mission 2

class NO_SCR_OpIntel_Action : NO_SCR_MissionSelectionAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		super.PerformAction(pOwnerEntity, pUserEntity);
		
		//Enables teleport trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("infil_A_trg"));
			if(trigger)
			trigger.SetActive(true);
		
		//Unlock next task
		IEntity taskEntity = GetGame().GetWorld().FindEntityByName("tsk_main_A_0");
        NO_SCR_EditorTask task = NO_SCR_EditorTask.Cast(taskEntity);
		task.ChangeStateOfTask(TriggerType.Create);
		task.ChangeStateOfTask(TriggerType.Assign);
		
		//Finish initital task
		IEntity taskEntityH = GetGame().GetWorld().FindEntityByName("tsk_hub");
		if (taskEntityH) {
        	NO_SCR_EditorTask taskH = NO_SCR_EditorTask.Cast(taskEntityH);
			taskH.ChangeStateOfTask(TriggerType.Finish);
		}
		
	}

}