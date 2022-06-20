//Custom script by Zeal to start the hitman operation in Mission 2

class NO_SCR_OpHitman_Action : NO_SCR_MissionSelectionAction
{
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
		{
		
		super.PerformAction(pOwnerEntity, pUserEntity);
		
		//Enables teleport trigger
		NO_SCR_PlayerTriggerEntity trigger = NO_SCR_PlayerTriggerEntity.Cast(GetGame().GetWorld().FindEntityByName("infil_C_trg"));
			if(trigger)
			trigger.SetActive(true);
		
		
		//Unlock next task
		IEntity taskEntity = GetGame().GetWorld().FindEntityByName("tsk_main_C_0");
        NO_SCR_EditorTask task = NO_SCR_EditorTask.Cast(taskEntity);
		task.ChangeStateOfTask(TriggerType.Assign);
		
		//Finish initital task
		IEntity taskEntityH = GetGame().GetWorld().FindEntityByName("tsk_hub");
		if (taskEntityH) {
        	NO_SCR_EditorTask taskH = NO_SCR_EditorTask.Cast(taskEntityH);
			taskH.ChangeStateOfTask(TriggerType.Finish);
		}
		
	}

}